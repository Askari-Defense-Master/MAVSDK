// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/offboard/offboard.proto)

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


class System;class OffboardImpl;

/**
 * @brief Control a drone with position, velocity, attitude or motor commands.
 *
 * The module is called offboard because the commands can be sent from external sources
 * as opposed to onboard control right inside the autopilot "board".
 *
 * Client code must specify a setpoint before starting offboard mode.
 * Mavsdk automatically sends setpoints at 20Hz (PX4 Offboard mode requires that setpoints
 * are minimally sent at 2Hz).
 */
class Offboard : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto offboard = Offboard(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Offboard(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto offboard = Offboard(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Offboard(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Offboard() override;





    /**
     * @brief Type for attitude body angles in NED reference frame (roll, pitch, yaw and thrust)
     */
    struct Attitude {
        
        float roll_deg{}; /**< @brief Roll angle (in degrees, positive is right side down) */
        float pitch_deg{}; /**< @brief Pitch angle (in degrees, positive is nose up) */
        float yaw_deg{}; /**< @brief Yaw angle (in degrees, positive is move nose to the right) */
        float thrust_value{}; /**< @brief Thrust (range: 0 to 1) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::Attitude` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::Attitude& lhs, const Offboard::Attitude& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::Attitude`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::Attitude const& attitude);




    /**
     * @brief Type for attitude as a quaternion with thrust
     */
    struct AttitudeQuaternion {
        
        float w{}; /**< @brief Quaternion w component (scalar part) */
        float x{}; /**< @brief Quaternion x component */
        float y{}; /**< @brief Quaternion y component */
        float z{}; /**< @brief Quaternion z component */
        float thrust_value{}; /**< @brief Thrust (range: 0 to 1) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::AttitudeQuaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::AttitudeQuaternion& lhs, const Offboard::AttitudeQuaternion& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::AttitudeQuaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::AttitudeQuaternion const& attitude_quaternion);




    /**
     * @brief Eight controls that will be given to the group. Each control is a normalized
     * (-1..+1) command value, which will be mapped and scaled through the mixer.
     */
    struct ActuatorControlGroup {
        
        std::vector<float> controls{}; /**< @brief Controls in the group */
    };

    /**
     * @brief Equal operator to compare two `Offboard::ActuatorControlGroup` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::ActuatorControlGroup& lhs, const Offboard::ActuatorControlGroup& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::ActuatorControlGroup`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::ActuatorControlGroup const& actuator_control_group);




    /**
     * @brief Type for actuator control.
     *
     * Control members should be normed to -1..+1 where 0 is neutral position.
     * Throttle for single rotation direction motors is 0..1, negative range for reverse direction.
     *
     * One group support eight controls.
     *
     * Up to 16 actuator controls can be set. To ignore an output group, set all it controls to NaN.
     * If one or more controls in group is not NaN, then all NaN controls will sent as zero.
     * The first 8 actuator controls internally map to control group 0, the latter 8 actuator
     * controls map to control group 1. Depending on what controls are set (instead of NaN) 1 or 2
     * MAVLink messages are actually sent.
     *
     * In PX4 v1.9.0 Only first four Control Groups are supported
     * (https://github.com/PX4/Firmware/blob/v1.9.0/src/modules/mavlink/mavlink_receiver.cpp#L980).
     */
    struct ActuatorControl {
        
        std::vector<ActuatorControlGroup> groups{}; /**< @brief Control groups. */
    };

    /**
     * @brief Equal operator to compare two `Offboard::ActuatorControl` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::ActuatorControl& lhs, const Offboard::ActuatorControl& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::ActuatorControl`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::ActuatorControl const& actuator_control);




    /**
     * @brief Type for attitude rate commands in body coordinates (roll, pitch, yaw angular rate and thrust)
     */
    struct AttitudeRate {
        
        float roll_deg_s{}; /**< @brief Roll angular rate (in degrees/second, positive for clock-wise looking from front) */
        float pitch_deg_s{}; /**< @brief Pitch angular rate (in degrees/second, positive for head/front moving up) */
        float yaw_deg_s{}; /**< @brief Yaw angular rate (in degrees/second, positive for clock-wise looking from above) */
        float thrust_value{}; /**< @brief Thrust (range: 0 to 1) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::AttitudeRate` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::AttitudeRate& lhs, const Offboard::AttitudeRate& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::AttitudeRate`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::AttitudeRate const& attitude_rate);




    /**
     * @brief Type for position commands in NED (North East Down) coordinates and yaw.
     */
    struct PositionNedYaw {
        
        float north_m{}; /**< @brief Position North (in metres) */
        float east_m{}; /**< @brief Position East (in metres) */
        float down_m{}; /**< @brief Position Down (in metres) */
        float yaw_deg{}; /**< @brief Yaw in degrees (0 North, positive is clock-wise looking from above) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::PositionNedYaw` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::PositionNedYaw& lhs, const Offboard::PositionNedYaw& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::PositionNedYaw`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::PositionNedYaw const& position_ned_yaw);





    /**
     * @brief Type for position commands in Global (Latitude, Longitude, Altitude) coordinates and yaw.
     */
    struct PositionGlobalYaw {
        
        /**
     * @brief Possible altitude options
     */
    enum class AltitudeType {
        RelHome, /**< @brief Altitude relative to the Home position. */
        Amsl, /**< @brief Altitude above mean sea level (AMSL). */
        Agl, /**< @brief Altitude above ground level (AGL). */
    };

    /**
     * @brief Stream operator to print information about a `Offboard::AltitudeType`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::PositionGlobalYaw::AltitudeType const& altitude_type);
        
        double lat_deg{}; /**< @brief Latitude (in degrees) */
        double lon_deg{}; /**< @brief Longitude (in degrees) */
        float alt_m{}; /**< @brief altitude (in metres) */
        float yaw_deg{}; /**< @brief Yaw in degrees (0 North, positive is clock-wise looking from above) */
        AltitudeType altitude_type{}; /**< @brief altitude type for this position */
    };

    /**
     * @brief Equal operator to compare two `Offboard::PositionGlobalYaw` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::PositionGlobalYaw& lhs, const Offboard::PositionGlobalYaw& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::PositionGlobalYaw`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::PositionGlobalYaw const& position_global_yaw);




    /**
     * @brief Type for velocity commands in body coordinates.
     */
    struct VelocityBodyYawspeed {
        
        float forward_m_s{}; /**< @brief Velocity forward (in metres/second) */
        float right_m_s{}; /**< @brief Velocity right (in metres/second) */
        float down_m_s{}; /**< @brief Velocity down (in metres/second) */
        float yawspeed_deg_s{}; /**< @brief Yaw angular rate (in degrees/second, positive for clock-wise looking from above) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::VelocityBodyYawspeed` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::VelocityBodyYawspeed& lhs, const Offboard::VelocityBodyYawspeed& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::VelocityBodyYawspeed`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::VelocityBodyYawspeed const& velocity_body_yawspeed);




    /**
     * @brief Type for velocity commands in NED (North East Down) coordinates and yaw.
     */
    struct VelocityNedYaw {
        
        float north_m_s{}; /**< @brief Velocity North (in metres/second) */
        float east_m_s{}; /**< @brief Velocity East (in metres/second) */
        float down_m_s{}; /**< @brief Velocity Down (in metres/second) */
        float yaw_deg{}; /**< @brief Yaw in degrees (0 North, positive is clock-wise looking from above) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::VelocityNedYaw` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::VelocityNedYaw& lhs, const Offboard::VelocityNedYaw& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::VelocityNedYaw`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::VelocityNedYaw const& velocity_ned_yaw);




    /**
     * @brief Type for acceleration commands in NED (North East Down) coordinates.
     */
    struct AccelerationNed {
        
        float north_m_s2{}; /**< @brief Acceleration North (in metres/second^2) */
        float east_m_s2{}; /**< @brief Acceleration East (in metres/second^2) */
        float down_m_s2{}; /**< @brief Acceleration Down (in metres/second^2) */
    };

    /**
     * @brief Equal operator to compare two `Offboard::AccelerationNed` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Offboard::AccelerationNed& lhs, const Offboard::AccelerationNed& rhs);

    /**
     * @brief Stream operator to print information about a `Offboard::AccelerationNed`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::AccelerationNed const& acceleration_ned);





    /**
     * @brief Possible results returned for offboard requests
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command denied. */
        Timeout, /**< @brief Request timed out. */
        NoSetpointSet, /**< @brief Cannot start without setpoint set. */
        Failed, /**< @brief Request failed. */
    };

    /**
     * @brief Stream operator to print information about a `Offboard::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Offboard::Result const& result);



    /**
     * @brief Callback type for asynchronous Offboard calls.
     */
    using ResultCallback = std::function<void(Result)>;




    /**
     * @brief Start offboard control.
     *
     * This function is non-blocking. See 'start' for the blocking counterpart.
     */
    void start_async(const ResultCallback callback);



    /**
     * @brief Start offboard control.
     *
     * This function is blocking. See 'start_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result start() const;




    /**
     * @brief Stop offboard control.
     *
     * The vehicle will be put into Hold mode: https://docs.px4.io/en/flight_modes/hold.html
     *
     * This function is non-blocking. See 'stop' for the blocking counterpart.
     */
    void stop_async(const ResultCallback callback);



    /**
     * @brief Stop offboard control.
     *
     * The vehicle will be put into Hold mode: https://docs.px4.io/en/flight_modes/hold.html
     *
     * This function is blocking. See 'stop_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result stop() const;






    /**
     * @brief Check if offboard control is active.
     *
     * True means that the vehicle is in offboard mode and we are actively sending
     * setpoints.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    bool is_active() const;






    /**
     * @brief Set the attitude in terms of roll, pitch and yaw in degrees with thrust.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_attitude(Attitude attitude) const;






    /**
     * @brief Set the attitude as a quaternion with thrust.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_attitude(AttitudeQuaternion attitude_quaternion) const;






    /**
     * @brief Set direct actuator control values to groups #0 and #1.
     *
     * First 8 controls will go to control group 0, the following 8 controls to control group 1 (if
     * actuator_control.num_controls more than 8).
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_actuator_control(ActuatorControl actuator_control) const;






    /**
     * @brief Set the attitude rate in terms of pitch, roll and yaw angular rate along with thrust.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_attitude_rate(AttitudeRate attitude_rate) const;






    /**
     * @brief Set the position in NED coordinates and yaw.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_position_ned(PositionNedYaw position_ned_yaw) const;






    /**
     * @brief Set the position in Global coordinates (latitude, longitude, altitude) and yaw
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_position_global(PositionGlobalYaw position_global_yaw) const;






    /**
     * @brief Set the velocity in body coordinates and yaw angular rate. Not available for fixed-wing aircraft.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_velocity_body(VelocityBodyYawspeed velocity_body_yawspeed) const;






    /**
     * @brief Set the velocity in NED coordinates and yaw. Not available for fixed-wing aircraft.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_velocity_ned(VelocityNedYaw velocity_ned_yaw) const;






    /**
     * @brief Set the position in NED coordinates, with the velocity to be used as feed-forward.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_position_velocity_ned(PositionNedYaw position_ned_yaw, VelocityNedYaw velocity_ned_yaw) const;






    /**
     * @brief Set the position, velocity and acceleration in NED coordinates, with velocity and acceleration used as feed-forward.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_position_velocity_acceleration_ned(PositionNedYaw position_ned_yaw, VelocityNedYaw velocity_ned_yaw, AccelerationNed acceleration_ned) const;






    /**
     * @brief Set the acceleration in NED coordinates.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_acceleration_ned(AccelerationNed acceleration_ned) const;




    /**
     * @brief Copy constructor.
     */
    Offboard(const Offboard& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Offboard& operator=(const Offboard&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<OffboardImpl> _impl;
};

} // namespace mavsdk