#include "mavsdk.h"
#include "plugins/camera/camera.h"
#include "plugins/camera_server/camera_server.h"
#include "log.h"
#include <future>
#include <mutex>
#include <thread>
#include <gtest/gtest.h>

using namespace mavsdk;

TEST(SystemTest, CameraTakePhoto)
{
    Mavsdk mavsdk_groundstation{Mavsdk::Configuration{ComponentType::GroundStation}};

    Mavsdk mavsdk_camera{Mavsdk::Configuration{ComponentType::Camera}};

    ASSERT_EQ(
        mavsdk_groundstation.add_any_connection("udpin://0.0.0.0:17000"),
        ConnectionResult::Success);
    ASSERT_EQ(
        mavsdk_camera.add_any_connection("udpout://127.0.0.1:17000"), ConnectionResult::Success);

    auto camera_server = CameraServer{mavsdk_camera.server_component()};

    CameraServer::Information information{};
    information.vendor_name = "CoolCameras";
    information.model_name = "Frozen Super";
    information.firmware_version = "4.0.0";
    information.definition_file_version = 1;
    information.definition_file_uri = "";
    camera_server.set_information(information);

    camera_server.subscribe_take_photo([&camera_server](int32_t index) {
        LogInfo() << "Let's take photo " << index;

        CameraServer::CaptureInfo info;
        info.index = index;
        info.is_success = true;

        camera_server.respond_take_photo(CameraServer::CameraFeedback::Ok, info);
    });

    camera_server.subscribe_set_mode([&](CameraServer::Mode mode) {
        LogInfo() << "Set mode to " << mode;
        camera_server.respond_set_mode(CameraServer::CameraFeedback::Ok);
    });

    auto prom = std::promise<std::shared_ptr<System>>();
    auto fut = prom.get_future();
    std::once_flag flag;

    auto handle = mavsdk_groundstation.subscribe_on_new_system([&]() {
        const auto system = mavsdk_groundstation.systems().back();
        if (system->is_connected() && system->has_camera()) {
            std::call_once(flag, [&]() { prom.set_value(system); });
        }
    });

    ASSERT_EQ(fut.wait_for(std::chrono::seconds(10)), std::future_status::ready);
    mavsdk_groundstation.unsubscribe_on_new_system(handle);
    auto system = fut.get();

    auto camera = Camera{system};

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    // We expect to find one camera.
    ASSERT_EQ(camera.camera_list().cameras.size(), 1);

    auto received_captured_info_prom = std::promise<void>{};
    auto received_captured_info_fut = received_captured_info_prom.get_future();

    Camera::CaptureInfoHandle capture_handle = camera.subscribe_capture_info(
        [&camera, &received_captured_info_prom, &capture_handle](Camera::CaptureInfo capture_info) {
            LogInfo() << "Received captured info for image: " << capture_info.index;
            // Unsubscribe again to prevent double setting promise.
            camera.unsubscribe_capture_info(capture_handle);
            received_captured_info_prom.set_value();
        });

    EXPECT_EQ(
        camera.take_photo(camera.camera_list().cameras[0].component_id), Camera::Result::Success);
    ASSERT_EQ(
        received_captured_info_fut.wait_for(std::chrono::seconds(10)), std::future_status::ready);
    received_captured_info_fut.get();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
