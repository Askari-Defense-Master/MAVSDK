// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/gimbal/gimbal.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>


#include "plugin_base.h"

#include "handle.h"

namespace mavsdk {


class System;class GimbalImpl;

/**
 * @brief Provide control over a gimbal.
 */
class Gimbal : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gimbal = Gimbal(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gimbal(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gimbal = Gimbal(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gimbal(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Gimbal() override;


    /**
     * @brief Gimbal mode type.
     */
    enum class GimbalMode {
        YawFollow, /**< @brief Yaw follow will point the gimbal to the vehicle heading. */
        YawLock, /**< @brief Yaw lock will fix the gimbal pointing to an absolute direction. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::GimbalMode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::GimbalMode const& gimbal_mode);

    /**
     * @brief Control mode
     */
    enum class ControlMode {
        None, /**< @brief Indicates that the component does not have control over the gimbal. */
        Primary, /**< @brief To take primary control over the gimbal. */
        Secondary, /**< @brief To take secondary control over the gimbal. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::ControlMode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::ControlMode const& control_mode);

    /**
     * @brief The send mode type
     */
    enum class SendMode {
        Once, /**< @brief Send command exactly once with quality of service (use for sporadic commands slower than 1 Hz). */
        Stream, /**< @brief Stream setpoint without quality of service (use for setpoints faster than 1 Hz).. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::SendMode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::SendMode const& send_mode);




    /**
     * @brief Quaternion type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Hamilton quaternion product definition is used.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     * The quaternion could also be written as w + xi + yj + zk.
     *
     * For more info see: https://en.wikipedia.org/wiki/Quaternion
     */
    struct Quaternion {
        
        float w{float(NAN)}; /**< @brief Quaternion entry 0, also denoted as a */
        float x{float(NAN)}; /**< @brief Quaternion entry 1, also denoted as b */
        float y{float(NAN)}; /**< @brief Quaternion entry 2, also denoted as c */
        float z{float(NAN)}; /**< @brief Quaternion entry 3, also denoted as d */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::Quaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::Quaternion& lhs, const Gimbal::Quaternion& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::Quaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::Quaternion const& quaternion);




    /**
     * @brief Euler angle type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Euler angles are converted using the 3-1-2 sequence instead of standard 3-2-1 in order
     * to avoid the gimbal lock at 90 degrees down.
     *
     * For more info see https://en.wikipedia.org/wiki/Euler_angles
     */
    struct EulerAngle {
        
        float roll_deg{float(NAN)}; /**< @brief Roll angle in degrees, positive is banking to the right */
        float pitch_deg{float(NAN)}; /**< @brief Pitch angle in degrees, positive is pitching nose up */
        float yaw_deg{float(NAN)}; /**< @brief Yaw angle in degrees, positive is clock-wise seen from above */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::EulerAngle` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::EulerAngle& lhs, const Gimbal::EulerAngle& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::EulerAngle`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::EulerAngle const& euler_angle);




    /**
     * @brief Gimbal angular rate type
     */
    struct AngularVelocityBody {
        
        float roll_rad_s{float(NAN)}; /**< @brief Roll angular velocity */
        float pitch_rad_s{float(NAN)}; /**< @brief Pitch angular velocity */
        float yaw_rad_s{float(NAN)}; /**< @brief Yaw angular velocity */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::AngularVelocityBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::AngularVelocityBody& lhs, const Gimbal::AngularVelocityBody& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::AngularVelocityBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::AngularVelocityBody const& angular_velocity_body);




    /**
     * @brief Gimbal attitude type
     */
    struct Attitude {
        
        int32_t gimbal_id{}; /**< @brief Gimbal ID */
        EulerAngle euler_angle_forward{}; /**< @brief Euler angle relative to forward */
        Quaternion quaternion_forward{}; /**< @brief Quaternion relative to forward */
        EulerAngle euler_angle_north{}; /**< @brief Euler angle relative to North */
        Quaternion quaternion_north{}; /**< @brief Quaternion relative to North */
        AngularVelocityBody angular_velocity{}; /**< @brief The angular rate */
        uint64_t timestamp_us{}; /**< @brief Timestamp in microseconds */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::Attitude` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::Attitude& lhs, const Gimbal::Attitude& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::Attitude`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::Attitude const& attitude);




    /**
     * @brief Gimbal list item
     */
    struct GimbalItem {
        
        int32_t gimbal_id{}; /**< @brief ID to address it, starting at 1 (0 means all gimbals) */
        std::string vendor_name{}; /**< @brief Vendor name */
        std::string model_name{}; /**< @brief Model name */
        std::string custom_name{}; /**< @brief Custom name name */
        int32_t gimbal_manager_component_id{}; /**< @brief MAVLink component of gimbal manager, for debugging purposes */
        int32_t gimbal_device_id{}; /**< @brief MAVLink component of gimbal device */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::GimbalItem` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::GimbalItem& lhs, const Gimbal::GimbalItem& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::GimbalItem`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::GimbalItem const& gimbal_item);




    /**
     * @brief Gimbal list
     */
    struct GimbalList {
        
        std::vector<GimbalItem> gimbals{}; /**< @brief Gimbal items. */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::GimbalList` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::GimbalList& lhs, const Gimbal::GimbalList& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::GimbalList`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::GimbalList const& gimbal_list);




    /**
     * @brief Control status
     */
    struct ControlStatus {
        
        int32_t gimbal_id{}; /**< @brief Gimbal ID */
        ControlMode control_mode{}; /**< @brief Control mode (none, primary or secondary) */
        int32_t sysid_primary_control{}; /**< @brief Sysid of the component that has primary control over the gimbal (0 if no one is in control) */
        int32_t compid_primary_control{}; /**< @brief Compid of the component that has primary control over the gimbal (0 if no one is in control) */
        int32_t sysid_secondary_control{}; /**< @brief Sysid of the component that has secondary control over the gimbal (0 if no one is in control) */
        int32_t compid_secondary_control{}; /**< @brief Compid of the component that has secondary control over the gimbal (0 if no one is in control) */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::ControlStatus` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::ControlStatus& lhs, const Gimbal::ControlStatus& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::ControlStatus`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::ControlStatus const& control_status);





    /**
     * @brief Possible results returned for gimbal commands.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Command was accepted. */
        Error, /**< @brief Error occurred sending the command. */
        Timeout, /**< @brief Command timed out. */
        Unsupported, /**< @brief Functionality not supported. */
        NoSystem, /**< @brief No system connected. */
        InvalidArgument, /**< @brief Invalid argument. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::Result const& result);



    /**
     * @brief Callback type for asynchronous Gimbal calls.
     */
    using ResultCallback = std::function<void(Result)>;




    /**
     * @brief Set gimbal roll, pitch and yaw angles.
     *
     * This sets the desired roll, pitch and yaw angles of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * Note that the roll angle needs to be set to 0 when send_mode is Once.
     *
     * This function is non-blocking. See 'set_angles' for the blocking counterpart.
     */
    void set_angles_async(int32_t gimbal_id, float roll_deg, float pitch_deg, float yaw_deg, GimbalMode gimbal_mode, SendMode send_mode, const ResultCallback callback);



    /**
     * @brief Set gimbal roll, pitch and yaw angles.
     *
     * This sets the desired roll, pitch and yaw angles of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * Note that the roll angle needs to be set to 0 when send_mode is Once.
     *
     * This function is blocking. See 'set_angles_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_angles(int32_t gimbal_id, float roll_deg, float pitch_deg, float yaw_deg, GimbalMode gimbal_mode, SendMode send_mode) const;




    /**
     * @brief Set gimbal angular rates.
     *
     * This sets the desired angular rates around roll, pitch and yaw axes of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually reach the angular rate.
     *
     * Note that the roll angle needs to be set to 0 when send_mode is Once.
     *
     * This function is non-blocking. See 'set_angular_rates' for the blocking counterpart.
     */
    void set_angular_rates_async(int32_t gimbal_id, float roll_rate_deg_s, float pitch_rate_deg_s, float yaw_rate_deg_s, GimbalMode gimbal_mode, SendMode send_mode, const ResultCallback callback);



    /**
     * @brief Set gimbal angular rates.
     *
     * This sets the desired angular rates around roll, pitch and yaw axes of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually reach the angular rate.
     *
     * Note that the roll angle needs to be set to 0 when send_mode is Once.
     *
     * This function is blocking. See 'set_angular_rates_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_angular_rates(int32_t gimbal_id, float roll_rate_deg_s, float pitch_rate_deg_s, float yaw_rate_deg_s, GimbalMode gimbal_mode, SendMode send_mode) const;




    /**
     * @brief Set gimbal region of interest (ROI).
     *
     * This sets a region of interest that the gimbal will point to.
     * The gimbal will continue to point to the specified region until it
     * receives a new command.
     * The function will return when the command is accepted, however, it might
     * take the gimbal longer to actually rotate to the ROI.
     *
     * This function is non-blocking. See 'set_roi_location' for the blocking counterpart.
     */
    void set_roi_location_async(int32_t gimbal_id, double latitude_deg, double longitude_deg, float altitude_m, const ResultCallback callback);



    /**
     * @brief Set gimbal region of interest (ROI).
     *
     * This sets a region of interest that the gimbal will point to.
     * The gimbal will continue to point to the specified region until it
     * receives a new command.
     * The function will return when the command is accepted, however, it might
     * take the gimbal longer to actually rotate to the ROI.
     *
     * This function is blocking. See 'set_roi_location_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_roi_location(int32_t gimbal_id, double latitude_deg, double longitude_deg, float altitude_m) const;




    /**
     * @brief Take control.
     *
     * There can be only two components in control of a gimbal at any given time.
     * One with "primary" control, and one with "secondary" control. The way the
     * secondary control is implemented is not specified and hence depends on the
     * vehicle.
     *
     * Components are expected to be cooperative, which means that they can
     * override each other and should therefore do it carefully.
     *
     * This function is non-blocking. See 'take_control' for the blocking counterpart.
     */
    void take_control_async(int32_t gimbal_id, ControlMode control_mode, const ResultCallback callback);



    /**
     * @brief Take control.
     *
     * There can be only two components in control of a gimbal at any given time.
     * One with "primary" control, and one with "secondary" control. The way the
     * secondary control is implemented is not specified and hence depends on the
     * vehicle.
     *
     * Components are expected to be cooperative, which means that they can
     * override each other and should therefore do it carefully.
     *
     * This function is blocking. See 'take_control_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result take_control(int32_t gimbal_id, ControlMode control_mode) const;




    /**
     * @brief Release control.
     *
     * Release control, such that other components can control the gimbal.
     *
     * This function is non-blocking. See 'release_control' for the blocking counterpart.
     */
    void release_control_async(int32_t gimbal_id, const ResultCallback callback);



    /**
     * @brief Release control.
     *
     * Release control, such that other components can control the gimbal.
     *
     * This function is blocking. See 'release_control_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result release_control(int32_t gimbal_id) const;




        

    /**
     * @brief Callback type for subscribe_gimbal_list.
     */
    using GimbalListCallback = std::function<void(GimbalList)>;

    /**
     * @brief Handle type for subscribe_gimbal_list.
     */
    using GimbalListHandle = Handle<GimbalList>;

    /**
     * @brief Subscribe to list of gimbals.
     *
     * This allows to find out what gimbals are connected to the system.
     * Based on the gimbal ID, we can then address a specific gimbal.
     */
    GimbalListHandle subscribe_gimbal_list(const GimbalListCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_gimbal_list
     */
    void unsubscribe_gimbal_list(GimbalListHandle handle);

        



    /**
     * @brief Poll for 'GimbalList' (blocking).
     *
     * @return One GimbalList update.
     */
    GimbalList gimbal_list() const;




        

    /**
     * @brief Callback type for subscribe_control_status.
     */
    using ControlStatusCallback = std::function<void(ControlStatus)>;

    /**
     * @brief Handle type for subscribe_control_status.
     */
    using ControlStatusHandle = Handle<ControlStatus>;

    /**
     * @brief Subscribe to control status updates.
     *
     * This allows a component to know if it has primary, secondary or
     * no control over the gimbal. Also, it gives the system and component ids
     * of the other components in control (if any).
     */
    ControlStatusHandle subscribe_control_status(const ControlStatusCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_control_status
     */
    void unsubscribe_control_status(ControlStatusHandle handle);

        








    /**
     * @brief Get control status for specific gimbal.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    std::pair<Result, Gimbal::ControlStatus> get_control_status(int32_t gimbal_id) const;




        

    /**
     * @brief Callback type for subscribe_attitude.
     */
    using AttitudeCallback = std::function<void(Attitude)>;

    /**
     * @brief Handle type for subscribe_attitude.
     */
    using AttitudeHandle = Handle<Attitude>;

    /**
     * @brief Subscribe to attitude updates.
     *
     * This gets you the gimbal's attitude and angular rate.
     */
    AttitudeHandle subscribe_attitude(const AttitudeCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_attitude
     */
    void unsubscribe_attitude(AttitudeHandle handle);

        








    /**
     * @brief Get attitude for specific gimbal.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    std::pair<Result, Gimbal::Attitude> get_attitude(int32_t gimbal_id) const;




    /**
     * @brief Copy constructor.
     */
    Gimbal(const Gimbal& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Gimbal& operator=(const Gimbal&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<GimbalImpl> _impl;
};

} // namespace mavsdk