// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/camera/camera.proto)

#include <iomanip>

#include "camera_impl.h"
#include "plugins/camera/camera.h"

namespace mavsdk {

using Option = Camera::Option;
using Setting = Camera::Setting;
using SettingOptions = Camera::SettingOptions;
using VideoStreamSettings = Camera::VideoStreamSettings;
using VideoStreamInfo = Camera::VideoStreamInfo;
using ModeUpdate = Camera::ModeUpdate;
using VideoStreamUpdate = Camera::VideoStreamUpdate;
using Storage = Camera::Storage;
using StorageUpdate = Camera::StorageUpdate;
using CurrentSettingsUpdate = Camera::CurrentSettingsUpdate;
using PossibleSettingOptionsUpdate = Camera::PossibleSettingOptionsUpdate;

using Position = Camera::Position;
using Quaternion = Camera::Quaternion;
using EulerAngle = Camera::EulerAngle;
using CaptureInfo = Camera::CaptureInfo;
using Information = Camera::Information;
using CameraList = Camera::CameraList;



Camera::Camera(System& system) : PluginBase(), _impl{std::make_unique<CameraImpl>(system)} {}

Camera::Camera(std::shared_ptr<System> system) : PluginBase(), _impl{std::make_unique<CameraImpl>(system)} {}


Camera::~Camera() {}



void Camera::take_photo_async(int32_t component_id, const ResultCallback callback)
{
    _impl->take_photo_async(component_id, callback);
}



Camera::Result Camera::take_photo(int32_t component_id) const
{
    return _impl->take_photo(component_id);
}



void Camera::start_photo_interval_async(int32_t component_id, float interval_s, const ResultCallback callback)
{
    _impl->start_photo_interval_async(component_id, interval_s, callback);
}



Camera::Result Camera::start_photo_interval(int32_t component_id, float interval_s) const
{
    return _impl->start_photo_interval(component_id, interval_s);
}



void Camera::stop_photo_interval_async(int32_t component_id, const ResultCallback callback)
{
    _impl->stop_photo_interval_async(component_id, callback);
}



Camera::Result Camera::stop_photo_interval(int32_t component_id) const
{
    return _impl->stop_photo_interval(component_id);
}



void Camera::start_video_async(int32_t component_id, const ResultCallback callback)
{
    _impl->start_video_async(component_id, callback);
}



Camera::Result Camera::start_video(int32_t component_id) const
{
    return _impl->start_video(component_id);
}



void Camera::stop_video_async(int32_t component_id, const ResultCallback callback)
{
    _impl->stop_video_async(component_id, callback);
}



Camera::Result Camera::stop_video(int32_t component_id) const
{
    return _impl->stop_video(component_id);
}





Camera::Result Camera::start_video_streaming(int32_t component_id, int32_t stream_id) const
{
    return _impl->start_video_streaming(component_id, stream_id);
}





Camera::Result Camera::stop_video_streaming(int32_t component_id, int32_t stream_id) const
{
    return _impl->stop_video_streaming(component_id, stream_id);
}



void Camera::set_mode_async(int32_t component_id, Mode mode, const ResultCallback callback)
{
    _impl->set_mode_async(component_id, mode, callback);
}



Camera::Result Camera::set_mode(int32_t component_id, Mode mode) const
{
    return _impl->set_mode(component_id, mode);
}



void Camera::list_photos_async(int32_t component_id, PhotosRange photos_range, const ListPhotosCallback callback)
{
    _impl->list_photos_async(component_id, photos_range, callback);
}



std::pair<Camera::Result, std::vector<Camera::CaptureInfo>> Camera::list_photos(int32_t component_id, PhotosRange photos_range) const
{
    return _impl->list_photos(component_id, photos_range);
}



    
Camera::CameraListHandle Camera::subscribe_camera_list(const CameraListCallback& callback)
{
    return _impl->subscribe_camera_list(callback);
}

void Camera::unsubscribe_camera_list(CameraListHandle handle)
{
    _impl->unsubscribe_camera_list(handle);
}
    




Camera::CameraList
Camera::camera_list() const
{
    return _impl->camera_list();
}



    
Camera::ModeHandle Camera::subscribe_mode(const ModeCallback& callback)
{
    return _impl->subscribe_mode(callback);
}

void Camera::unsubscribe_mode(ModeHandle handle)
{
    _impl->unsubscribe_mode(handle);
}
    







std::pair<Camera::Result, Camera::Mode> Camera::get_mode(int32_t component_id) const
{
    return _impl->get_mode(component_id);
}



    
Camera::VideoStreamInfoHandle Camera::subscribe_video_stream_info(const VideoStreamInfoCallback& callback)
{
    return _impl->subscribe_video_stream_info(callback);
}

void Camera::unsubscribe_video_stream_info(VideoStreamInfoHandle handle)
{
    _impl->unsubscribe_video_stream_info(handle);
}
    







std::pair<Camera::Result, Camera::VideoStreamInfo> Camera::get_video_stream_info(int32_t component_id) const
{
    return _impl->get_video_stream_info(component_id);
}



    
Camera::CaptureInfoHandle Camera::subscribe_capture_info(const CaptureInfoCallback& callback)
{
    return _impl->subscribe_capture_info(callback);
}

void Camera::unsubscribe_capture_info(CaptureInfoHandle handle)
{
    _impl->unsubscribe_capture_info(handle);
}
    





    
Camera::StorageHandle Camera::subscribe_storage(const StorageCallback& callback)
{
    return _impl->subscribe_storage(callback);
}

void Camera::unsubscribe_storage(StorageHandle handle)
{
    _impl->unsubscribe_storage(handle);
}
    







std::pair<Camera::Result, Camera::Storage> Camera::get_storage(int32_t component_id) const
{
    return _impl->get_storage(component_id);
}



    
Camera::CurrentSettingsHandle Camera::subscribe_current_settings(const CurrentSettingsCallback& callback)
{
    return _impl->subscribe_current_settings(callback);
}

void Camera::unsubscribe_current_settings(CurrentSettingsHandle handle)
{
    _impl->unsubscribe_current_settings(handle);
}
    







std::pair<Camera::Result, std::vector<Camera::Setting>> Camera::get_current_settings(int32_t component_id) const
{
    return _impl->get_current_settings(component_id);
}



    
Camera::PossibleSettingOptionsHandle Camera::subscribe_possible_setting_options(const PossibleSettingOptionsCallback& callback)
{
    return _impl->subscribe_possible_setting_options(callback);
}

void Camera::unsubscribe_possible_setting_options(PossibleSettingOptionsHandle handle)
{
    _impl->unsubscribe_possible_setting_options(handle);
}
    







std::pair<Camera::Result, std::vector<Camera::SettingOptions>> Camera::get_possible_setting_options(int32_t component_id) const
{
    return _impl->get_possible_setting_options(component_id);
}



void Camera::set_setting_async(int32_t component_id, Setting setting, const ResultCallback callback)
{
    _impl->set_setting_async(component_id, setting, callback);
}



Camera::Result Camera::set_setting(int32_t component_id, Setting setting) const
{
    return _impl->set_setting(component_id, setting);
}



void Camera::get_setting_async(int32_t component_id, Setting setting, const GetSettingCallback callback)
{
    _impl->get_setting_async(component_id, setting, callback);
}



std::pair<Camera::Result, Camera::Setting> Camera::get_setting(int32_t component_id, Setting setting) const
{
    return _impl->get_setting(component_id, setting);
}



void Camera::format_storage_async(int32_t component_id, int32_t storage_id, const ResultCallback callback)
{
    _impl->format_storage_async(component_id, storage_id, callback);
}



Camera::Result Camera::format_storage(int32_t component_id, int32_t storage_id) const
{
    return _impl->format_storage(component_id, storage_id);
}



void Camera::reset_settings_async(int32_t component_id, const ResultCallback callback)
{
    _impl->reset_settings_async(component_id, callback);
}



Camera::Result Camera::reset_settings(int32_t component_id) const
{
    return _impl->reset_settings(component_id);
}



void Camera::zoom_in_start_async(int32_t component_id, const ResultCallback callback)
{
    _impl->zoom_in_start_async(component_id, callback);
}



Camera::Result Camera::zoom_in_start(int32_t component_id) const
{
    return _impl->zoom_in_start(component_id);
}



void Camera::zoom_out_start_async(int32_t component_id, const ResultCallback callback)
{
    _impl->zoom_out_start_async(component_id, callback);
}



Camera::Result Camera::zoom_out_start(int32_t component_id) const
{
    return _impl->zoom_out_start(component_id);
}



void Camera::zoom_stop_async(int32_t component_id, const ResultCallback callback)
{
    _impl->zoom_stop_async(component_id, callback);
}



Camera::Result Camera::zoom_stop(int32_t component_id) const
{
    return _impl->zoom_stop(component_id);
}



void Camera::zoom_range_async(int32_t component_id, float range, const ResultCallback callback)
{
    _impl->zoom_range_async(component_id, range, callback);
}



Camera::Result Camera::zoom_range(int32_t component_id, float range) const
{
    return _impl->zoom_range(component_id, range);
}



void Camera::track_point_async(int32_t component_id, float point_x, float point_y, float radius, const ResultCallback callback)
{
    _impl->track_point_async(component_id, point_x, point_y, radius, callback);
}



Camera::Result Camera::track_point(int32_t component_id, float point_x, float point_y, float radius) const
{
    return _impl->track_point(component_id, point_x, point_y, radius);
}



void Camera::track_rectangle_async(int32_t component_id, float top_left_x, float top_left_y, float bottom_right_x, float bottom_right_y, const ResultCallback callback)
{
    _impl->track_rectangle_async(component_id, top_left_x, top_left_y, bottom_right_x, bottom_right_y, callback);
}



Camera::Result Camera::track_rectangle(int32_t component_id, float top_left_x, float top_left_y, float bottom_right_x, float bottom_right_y) const
{
    return _impl->track_rectangle(component_id, top_left_x, top_left_y, bottom_right_x, bottom_right_y);
}



void Camera::track_stop_async(int32_t component_id, const ResultCallback callback)
{
    _impl->track_stop_async(component_id, callback);
}



Camera::Result Camera::track_stop(int32_t component_id) const
{
    return _impl->track_stop(component_id);
}



void Camera::focus_in_start_async(int32_t component_id, const ResultCallback callback)
{
    _impl->focus_in_start_async(component_id, callback);
}



Camera::Result Camera::focus_in_start(int32_t component_id) const
{
    return _impl->focus_in_start(component_id);
}



void Camera::focus_out_start_async(int32_t component_id, const ResultCallback callback)
{
    _impl->focus_out_start_async(component_id, callback);
}



Camera::Result Camera::focus_out_start(int32_t component_id) const
{
    return _impl->focus_out_start(component_id);
}



void Camera::focus_stop_async(int32_t component_id, const ResultCallback callback)
{
    _impl->focus_stop_async(component_id, callback);
}



Camera::Result Camera::focus_stop(int32_t component_id) const
{
    return _impl->focus_stop(component_id);
}



void Camera::focus_range_async(int32_t component_id, float range, const ResultCallback callback)
{
    _impl->focus_range_async(component_id, range, callback);
}



Camera::Result Camera::focus_range(int32_t component_id, float range) const
{
    return _impl->focus_range(component_id, range);
}



bool operator==(const Camera::Option& lhs, const Camera::Option& rhs)
{
    return
        (rhs.option_id == lhs.option_id) &&
        (rhs.option_description == lhs.option_description);
}

std::ostream& operator<<(std::ostream& str, Camera::Option const& option)
{
    str << std::setprecision(15);
    str << "option:" << '\n'
        << "{\n";
    str << "    option_id: " << option.option_id << '\n';
    str << "    option_description: " << option.option_description << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::Setting& lhs, const Camera::Setting& rhs)
{
    return
        (rhs.setting_id == lhs.setting_id) &&
        (rhs.setting_description == lhs.setting_description) &&
        (rhs.option == lhs.option) &&
        (rhs.is_range == lhs.is_range);
}

std::ostream& operator<<(std::ostream& str, Camera::Setting const& setting)
{
    str << std::setprecision(15);
    str << "setting:" << '\n'
        << "{\n";
    str << "    setting_id: " << setting.setting_id << '\n';
    str << "    setting_description: " << setting.setting_description << '\n';
    str << "    option: " << setting.option << '\n';
    str << "    is_range: " << setting.is_range << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::SettingOptions& lhs, const Camera::SettingOptions& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.setting_id == lhs.setting_id) &&
        (rhs.setting_description == lhs.setting_description) &&
        (rhs.options == lhs.options) &&
        (rhs.is_range == lhs.is_range);
}

std::ostream& operator<<(std::ostream& str, Camera::SettingOptions const& setting_options)
{
    str << std::setprecision(15);
    str << "setting_options:" << '\n'
        << "{\n";
    str << "    component_id: " << setting_options.component_id << '\n';
    str << "    setting_id: " << setting_options.setting_id << '\n';
    str << "    setting_description: " << setting_options.setting_description << '\n';
    str << "    options: [";
    for (auto it = setting_options.options.begin(); it != setting_options.options.end(); ++it) {
        str << *it;
        str << (it + 1 != setting_options.options.end() ? ", " : "]\n");
    }
    str << "    is_range: " << setting_options.is_range << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::VideoStreamSettings& lhs, const Camera::VideoStreamSettings& rhs)
{
    return
        ((std::isnan(rhs.frame_rate_hz) && std::isnan(lhs.frame_rate_hz)) || rhs.frame_rate_hz == lhs.frame_rate_hz) &&
        (rhs.horizontal_resolution_pix == lhs.horizontal_resolution_pix) &&
        (rhs.vertical_resolution_pix == lhs.vertical_resolution_pix) &&
        (rhs.bit_rate_b_s == lhs.bit_rate_b_s) &&
        (rhs.rotation_deg == lhs.rotation_deg) &&
        (rhs.uri == lhs.uri) &&
        ((std::isnan(rhs.horizontal_fov_deg) && std::isnan(lhs.horizontal_fov_deg)) || rhs.horizontal_fov_deg == lhs.horizontal_fov_deg);
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamSettings const& video_stream_settings)
{
    str << std::setprecision(15);
    str << "video_stream_settings:" << '\n'
        << "{\n";
    str << "    frame_rate_hz: " << video_stream_settings.frame_rate_hz << '\n';
    str << "    horizontal_resolution_pix: " << video_stream_settings.horizontal_resolution_pix << '\n';
    str << "    vertical_resolution_pix: " << video_stream_settings.vertical_resolution_pix << '\n';
    str << "    bit_rate_b_s: " << video_stream_settings.bit_rate_b_s << '\n';
    str << "    rotation_deg: " << video_stream_settings.rotation_deg << '\n';
    str << "    uri: " << video_stream_settings.uri << '\n';
    str << "    horizontal_fov_deg: " << video_stream_settings.horizontal_fov_deg << '\n';
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, Camera::VideoStreamInfo::VideoStreamStatus const& video_stream_status)
{
    switch (video_stream_status) {
        case Camera::VideoStreamInfo::VideoStreamStatus::NotRunning:
            return str << "Not Running";
        case Camera::VideoStreamInfo::VideoStreamStatus::InProgress:
            return str << "In Progress";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamInfo::VideoStreamSpectrum const& video_stream_spectrum)
{
    switch (video_stream_spectrum) {
        case Camera::VideoStreamInfo::VideoStreamSpectrum::Unknown:
            return str << "Unknown";
        case Camera::VideoStreamInfo::VideoStreamSpectrum::VisibleLight:
            return str << "Visible Light";
        case Camera::VideoStreamInfo::VideoStreamSpectrum::Infrared:
            return str << "Infrared";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Camera::VideoStreamInfo& lhs, const Camera::VideoStreamInfo& rhs)
{
    return
        (rhs.stream_id == lhs.stream_id) &&
        (rhs.settings == lhs.settings) &&
        (rhs.status == lhs.status) &&
        (rhs.spectrum == lhs.spectrum);
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamInfo const& video_stream_info)
{
    str << std::setprecision(15);
    str << "video_stream_info:" << '\n'
        << "{\n";
    str << "    stream_id: " << video_stream_info.stream_id << '\n';
    str << "    settings: " << video_stream_info.settings << '\n';
    str << "    status: " << video_stream_info.status << '\n';
    str << "    spectrum: " << video_stream_info.spectrum << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::ModeUpdate& lhs, const Camera::ModeUpdate& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.mode == lhs.mode);
}

std::ostream& operator<<(std::ostream& str, Camera::ModeUpdate const& mode_update)
{
    str << std::setprecision(15);
    str << "mode_update:" << '\n'
        << "{\n";
    str << "    component_id: " << mode_update.component_id << '\n';
    str << "    mode: " << mode_update.mode << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::VideoStreamUpdate& lhs, const Camera::VideoStreamUpdate& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.video_stream_info == lhs.video_stream_info);
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamUpdate const& video_stream_update)
{
    str << std::setprecision(15);
    str << "video_stream_update:" << '\n'
        << "{\n";
    str << "    component_id: " << video_stream_update.component_id << '\n';
    str << "    video_stream_info: " << video_stream_update.video_stream_info << '\n';
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, Camera::Storage::StorageStatus const& storage_status)
{
    switch (storage_status) {
        case Camera::Storage::StorageStatus::NotAvailable:
            return str << "Not Available";
        case Camera::Storage::StorageStatus::Unformatted:
            return str << "Unformatted";
        case Camera::Storage::StorageStatus::Formatted:
            return str << "Formatted";
        case Camera::Storage::StorageStatus::NotSupported:
            return str << "Not Supported";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Camera::Storage::StorageType const& storage_type)
{
    switch (storage_type) {
        case Camera::Storage::StorageType::Unknown:
            return str << "Unknown";
        case Camera::Storage::StorageType::UsbStick:
            return str << "Usb Stick";
        case Camera::Storage::StorageType::Sd:
            return str << "Sd";
        case Camera::Storage::StorageType::Microsd:
            return str << "Microsd";
        case Camera::Storage::StorageType::Hd:
            return str << "Hd";
        case Camera::Storage::StorageType::Other:
            return str << "Other";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Camera::Storage& lhs, const Camera::Storage& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.video_on == lhs.video_on) &&
        (rhs.photo_interval_on == lhs.photo_interval_on) &&
        ((std::isnan(rhs.used_storage_mib) && std::isnan(lhs.used_storage_mib)) || rhs.used_storage_mib == lhs.used_storage_mib) &&
        ((std::isnan(rhs.available_storage_mib) && std::isnan(lhs.available_storage_mib)) || rhs.available_storage_mib == lhs.available_storage_mib) &&
        ((std::isnan(rhs.total_storage_mib) && std::isnan(lhs.total_storage_mib)) || rhs.total_storage_mib == lhs.total_storage_mib) &&
        ((std::isnan(rhs.recording_time_s) && std::isnan(lhs.recording_time_s)) || rhs.recording_time_s == lhs.recording_time_s) &&
        (rhs.media_folder_name == lhs.media_folder_name) &&
        (rhs.storage_status == lhs.storage_status) &&
        (rhs.storage_id == lhs.storage_id) &&
        (rhs.storage_type == lhs.storage_type);
}

std::ostream& operator<<(std::ostream& str, Camera::Storage const& storage)
{
    str << std::setprecision(15);
    str << "storage:" << '\n'
        << "{\n";
    str << "    component_id: " << storage.component_id << '\n';
    str << "    video_on: " << storage.video_on << '\n';
    str << "    photo_interval_on: " << storage.photo_interval_on << '\n';
    str << "    used_storage_mib: " << storage.used_storage_mib << '\n';
    str << "    available_storage_mib: " << storage.available_storage_mib << '\n';
    str << "    total_storage_mib: " << storage.total_storage_mib << '\n';
    str << "    recording_time_s: " << storage.recording_time_s << '\n';
    str << "    media_folder_name: " << storage.media_folder_name << '\n';
    str << "    storage_status: " << storage.storage_status << '\n';
    str << "    storage_id: " << storage.storage_id << '\n';
    str << "    storage_type: " << storage.storage_type << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::StorageUpdate& lhs, const Camera::StorageUpdate& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.storage == lhs.storage);
}

std::ostream& operator<<(std::ostream& str, Camera::StorageUpdate const& storage_update)
{
    str << std::setprecision(15);
    str << "storage_update:" << '\n'
        << "{\n";
    str << "    component_id: " << storage_update.component_id << '\n';
    str << "    storage: " << storage_update.storage << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::CurrentSettingsUpdate& lhs, const Camera::CurrentSettingsUpdate& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.current_settings == lhs.current_settings);
}

std::ostream& operator<<(std::ostream& str, Camera::CurrentSettingsUpdate const& current_settings_update)
{
    str << std::setprecision(15);
    str << "current_settings_update:" << '\n'
        << "{\n";
    str << "    component_id: " << current_settings_update.component_id << '\n';
    str << "    current_settings: [";
    for (auto it = current_settings_update.current_settings.begin(); it != current_settings_update.current_settings.end(); ++it) {
        str << *it;
        str << (it + 1 != current_settings_update.current_settings.end() ? ", " : "]\n");
    }
    str << '}';
    return str;
}


bool operator==(const Camera::PossibleSettingOptionsUpdate& lhs, const Camera::PossibleSettingOptionsUpdate& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.setting_options == lhs.setting_options);
}

std::ostream& operator<<(std::ostream& str, Camera::PossibleSettingOptionsUpdate const& possible_setting_options_update)
{
    str << std::setprecision(15);
    str << "possible_setting_options_update:" << '\n'
        << "{\n";
    str << "    component_id: " << possible_setting_options_update.component_id << '\n';
    str << "    setting_options: [";
    for (auto it = possible_setting_options_update.setting_options.begin(); it != possible_setting_options_update.setting_options.end(); ++it) {
        str << *it;
        str << (it + 1 != possible_setting_options_update.setting_options.end() ? ", " : "]\n");
    }
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, Camera::Result const& result)
{
    switch (result) {
        case Camera::Result::Unknown:
            return str << "Unknown";
        case Camera::Result::Success:
            return str << "Success";
        case Camera::Result::InProgress:
            return str << "In Progress";
        case Camera::Result::Busy:
            return str << "Busy";
        case Camera::Result::Denied:
            return str << "Denied";
        case Camera::Result::Error:
            return str << "Error";
        case Camera::Result::Timeout:
            return str << "Timeout";
        case Camera::Result::WrongArgument:
            return str << "Wrong Argument";
        case Camera::Result::NoSystem:
            return str << "No System";
        case Camera::Result::ProtocolUnsupported:
            return str << "Protocol Unsupported";
        case Camera::Result::Unavailable:
            return str << "Unavailable";
        case Camera::Result::CameraIdInvalid:
            return str << "Camera Id Invalid";
        case Camera::Result::ActionUnsupported:
            return str << "Action Unsupported";
        default:
            return str << "Unknown";
    }
}


bool operator==(const Camera::Position& lhs, const Camera::Position& rhs)
{
    return
        ((std::isnan(rhs.latitude_deg) && std::isnan(lhs.latitude_deg)) || rhs.latitude_deg == lhs.latitude_deg) &&
        ((std::isnan(rhs.longitude_deg) && std::isnan(lhs.longitude_deg)) || rhs.longitude_deg == lhs.longitude_deg) &&
        ((std::isnan(rhs.absolute_altitude_m) && std::isnan(lhs.absolute_altitude_m)) || rhs.absolute_altitude_m == lhs.absolute_altitude_m) &&
        ((std::isnan(rhs.relative_altitude_m) && std::isnan(lhs.relative_altitude_m)) || rhs.relative_altitude_m == lhs.relative_altitude_m);
}

std::ostream& operator<<(std::ostream& str, Camera::Position const& position)
{
    str << std::setprecision(15);
    str << "position:" << '\n'
        << "{\n";
    str << "    latitude_deg: " << position.latitude_deg << '\n';
    str << "    longitude_deg: " << position.longitude_deg << '\n';
    str << "    absolute_altitude_m: " << position.absolute_altitude_m << '\n';
    str << "    relative_altitude_m: " << position.relative_altitude_m << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::Quaternion& lhs, const Camera::Quaternion& rhs)
{
    return
        ((std::isnan(rhs.w) && std::isnan(lhs.w)) || rhs.w == lhs.w) &&
        ((std::isnan(rhs.x) && std::isnan(lhs.x)) || rhs.x == lhs.x) &&
        ((std::isnan(rhs.y) && std::isnan(lhs.y)) || rhs.y == lhs.y) &&
        ((std::isnan(rhs.z) && std::isnan(lhs.z)) || rhs.z == lhs.z);
}

std::ostream& operator<<(std::ostream& str, Camera::Quaternion const& quaternion)
{
    str << std::setprecision(15);
    str << "quaternion:" << '\n'
        << "{\n";
    str << "    w: " << quaternion.w << '\n';
    str << "    x: " << quaternion.x << '\n';
    str << "    y: " << quaternion.y << '\n';
    str << "    z: " << quaternion.z << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::EulerAngle& lhs, const Camera::EulerAngle& rhs)
{
    return
        ((std::isnan(rhs.roll_deg) && std::isnan(lhs.roll_deg)) || rhs.roll_deg == lhs.roll_deg) &&
        ((std::isnan(rhs.pitch_deg) && std::isnan(lhs.pitch_deg)) || rhs.pitch_deg == lhs.pitch_deg) &&
        ((std::isnan(rhs.yaw_deg) && std::isnan(lhs.yaw_deg)) || rhs.yaw_deg == lhs.yaw_deg);
}

std::ostream& operator<<(std::ostream& str, Camera::EulerAngle const& euler_angle)
{
    str << std::setprecision(15);
    str << "euler_angle:" << '\n'
        << "{\n";
    str << "    roll_deg: " << euler_angle.roll_deg << '\n';
    str << "    pitch_deg: " << euler_angle.pitch_deg << '\n';
    str << "    yaw_deg: " << euler_angle.yaw_deg << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::CaptureInfo& lhs, const Camera::CaptureInfo& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.position == lhs.position) &&
        (rhs.attitude_quaternion == lhs.attitude_quaternion) &&
        (rhs.attitude_euler_angle == lhs.attitude_euler_angle) &&
        (rhs.time_utc_us == lhs.time_utc_us) &&
        (rhs.is_success == lhs.is_success) &&
        (rhs.index == lhs.index) &&
        (rhs.file_url == lhs.file_url);
}

std::ostream& operator<<(std::ostream& str, Camera::CaptureInfo const& capture_info)
{
    str << std::setprecision(15);
    str << "capture_info:" << '\n'
        << "{\n";
    str << "    component_id: " << capture_info.component_id << '\n';
    str << "    position: " << capture_info.position << '\n';
    str << "    attitude_quaternion: " << capture_info.attitude_quaternion << '\n';
    str << "    attitude_euler_angle: " << capture_info.attitude_euler_angle << '\n';
    str << "    time_utc_us: " << capture_info.time_utc_us << '\n';
    str << "    is_success: " << capture_info.is_success << '\n';
    str << "    index: " << capture_info.index << '\n';
    str << "    file_url: " << capture_info.file_url << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::Information& lhs, const Camera::Information& rhs)
{
    return
        (rhs.component_id == lhs.component_id) &&
        (rhs.vendor_name == lhs.vendor_name) &&
        (rhs.model_name == lhs.model_name) &&
        ((std::isnan(rhs.focal_length_mm) && std::isnan(lhs.focal_length_mm)) || rhs.focal_length_mm == lhs.focal_length_mm) &&
        ((std::isnan(rhs.horizontal_sensor_size_mm) && std::isnan(lhs.horizontal_sensor_size_mm)) || rhs.horizontal_sensor_size_mm == lhs.horizontal_sensor_size_mm) &&
        ((std::isnan(rhs.vertical_sensor_size_mm) && std::isnan(lhs.vertical_sensor_size_mm)) || rhs.vertical_sensor_size_mm == lhs.vertical_sensor_size_mm) &&
        (rhs.horizontal_resolution_px == lhs.horizontal_resolution_px) &&
        (rhs.vertical_resolution_px == lhs.vertical_resolution_px);
}

std::ostream& operator<<(std::ostream& str, Camera::Information const& information)
{
    str << std::setprecision(15);
    str << "information:" << '\n'
        << "{\n";
    str << "    component_id: " << information.component_id << '\n';
    str << "    vendor_name: " << information.vendor_name << '\n';
    str << "    model_name: " << information.model_name << '\n';
    str << "    focal_length_mm: " << information.focal_length_mm << '\n';
    str << "    horizontal_sensor_size_mm: " << information.horizontal_sensor_size_mm << '\n';
    str << "    vertical_sensor_size_mm: " << information.vertical_sensor_size_mm << '\n';
    str << "    horizontal_resolution_px: " << information.horizontal_resolution_px << '\n';
    str << "    vertical_resolution_px: " << information.vertical_resolution_px << '\n';
    str << '}';
    return str;
}


bool operator==(const Camera::CameraList& lhs, const Camera::CameraList& rhs)
{
    return
        (rhs.cameras == lhs.cameras);
}

std::ostream& operator<<(std::ostream& str, Camera::CameraList const& camera_list)
{
    str << std::setprecision(15);
    str << "camera_list:" << '\n'
        << "{\n";
    str << "    cameras: [";
    for (auto it = camera_list.cameras.begin(); it != camera_list.cameras.end(); ++it) {
        str << *it;
        str << (it + 1 != camera_list.cameras.end() ? ", " : "]\n");
    }
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, Camera::Mode const& mode)
{
    switch (mode) {
        case Camera::Mode::Unknown:
            return str << "Unknown";
        case Camera::Mode::Photo:
            return str << "Photo";
        case Camera::Mode::Video:
            return str << "Video";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Camera::PhotosRange const& photos_range)
{
    switch (photos_range) {
        case Camera::PhotosRange::All:
            return str << "All";
        case Camera::PhotosRange::SinceConnection:
            return str << "Since Connection";
        default:
            return str << "Unknown";
    }
}


} // namespace mavsdk