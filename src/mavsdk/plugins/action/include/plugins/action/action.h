// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/action/action.proto)

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


class System;class ActionImpl;

/**
 * @brief Enable simple actions such as arming, taking off, and landing.
 */
class Action : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto action = Action(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Action(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto action = Action(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Action(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Action() override;


    /**
     * @brief Yaw behaviour during orbit flight.
     */
    enum class OrbitYawBehavior {
        HoldFrontToCircleCenter, /**< @brief Vehicle front points to the center (default). */
        HoldInitialHeading, /**< @brief Vehicle front holds heading when message received. */
        Uncontrolled, /**< @brief Yaw uncontrolled. */
        HoldFrontTangentToCircle, /**< @brief Vehicle front follows flight path (tangential to circle). */
        RcControlled, /**< @brief Yaw controlled by RC input. */
    };

    /**
     * @brief Stream operator to print information about a `Action::OrbitYawBehavior`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Action::OrbitYawBehavior const& orbit_yaw_behavior);





    /**
     * @brief Possible results returned for action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request was successful. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command refused by vehicle. */
        CommandDeniedLandedStateUnknown, /**< @brief Command refused because landed state is unknown. */
        CommandDeniedNotLanded, /**< @brief Command refused because vehicle not landed. */
        Timeout, /**< @brief Request timed out. */
        VtolTransitionSupportUnknown, /**< @brief Hybrid/VTOL transition support is unknown. */
        NoVtolTransitionSupport, /**< @brief Vehicle does not support hybrid/VTOL transitions. */
        ParameterError, /**< @brief Error getting or setting parameter. */
        Unsupported, /**< @brief Action not supported. */
        Failed, /**< @brief Action failed. */
        InvalidArgument, /**< @brief Invalid argument. */
    };

    /**
     * @brief Stream operator to print information about a `Action::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Action::Result const& result);



    /**
     * @brief Callback type for asynchronous Action calls.
     */
    using ResultCallback = std::function<void(Result)>;




    /**
     * @brief Send command to arm the drone.
     *
     * Arming a drone normally causes motors to spin at idle.
     * Before arming take all safety precautions and stand clear of the drone!
     *
     * This function is non-blocking. See 'arm' for the blocking counterpart.
     */
    void arm_async(const ResultCallback callback);



    /**
     * @brief Send command to arm the drone.
     *
     * Arming a drone normally causes motors to spin at idle.
     * Before arming take all safety precautions and stand clear of the drone!
     *
     * This function is blocking. See 'arm_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result arm() const;




    /**
     * @brief Send command to force-arm the drone without any checks.
     *
     * Attention: this is not to be used for normal flying but only bench tests!
     *
     * Arming a drone normally causes motors to spin at idle.
     * Before arming take all safety precautions and stand clear of the drone!
     *
     * This function is non-blocking. See 'arm_force' for the blocking counterpart.
     */
    void arm_force_async(const ResultCallback callback);



    /**
     * @brief Send command to force-arm the drone without any checks.
     *
     * Attention: this is not to be used for normal flying but only bench tests!
     *
     * Arming a drone normally causes motors to spin at idle.
     * Before arming take all safety precautions and stand clear of the drone!
     *
     * This function is blocking. See 'arm_force_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result arm_force() const;




    /**
     * @brief Send command to disarm the drone.
     *
     * This will disarm a drone that considers itself landed. If flying, the drone should
     * reject the disarm command. Disarming means that all motors will stop.
     *
     * This function is non-blocking. See 'disarm' for the blocking counterpart.
     */
    void disarm_async(const ResultCallback callback);



    /**
     * @brief Send command to disarm the drone.
     *
     * This will disarm a drone that considers itself landed. If flying, the drone should
     * reject the disarm command. Disarming means that all motors will stop.
     *
     * This function is blocking. See 'disarm_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result disarm() const;




    /**
     * @brief Send command to take off and hover.
     *
     * This switches the drone into position control mode and commands
     * it to take off and hover at the takeoff altitude.
     *
     * Note that the vehicle must be armed before it can take off.
     *
     * This function is non-blocking. See 'takeoff' for the blocking counterpart.
     */
    void takeoff_async(const ResultCallback callback);



    /**
     * @brief Send command to take off and hover.
     *
     * This switches the drone into position control mode and commands
     * it to take off and hover at the takeoff altitude.
     *
     * Note that the vehicle must be armed before it can take off.
     *
     * This function is blocking. See 'takeoff_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result takeoff() const;




    /**
     * @brief Send command to land at the current position.
     *
     * This switches the drone to 'Land' flight mode.
     *
     * This function is non-blocking. See 'land' for the blocking counterpart.
     */
    void land_async(const ResultCallback callback);



    /**
     * @brief Send command to land at the current position.
     *
     * This switches the drone to 'Land' flight mode.
     *
     * This function is blocking. See 'land_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result land() const;




    /**
     * @brief Send command to reboot the drone components.
     *
     * This will reboot the autopilot, companion computer, camera and gimbal.
     *
     * This function is non-blocking. See 'reboot' for the blocking counterpart.
     */
    void reboot_async(const ResultCallback callback);



    /**
     * @brief Send command to reboot the drone components.
     *
     * This will reboot the autopilot, companion computer, camera and gimbal.
     *
     * This function is blocking. See 'reboot_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result reboot() const;




    /**
     * @brief Send command to shut down the drone components.
     *
     * This will shut down the autopilot, onboard computer, camera and gimbal.
     * This command should only be used when the autopilot is disarmed and autopilots commonly
     * reject it if they are not already ready to shut down.
     *
     * This function is non-blocking. See 'shutdown' for the blocking counterpart.
     */
    void shutdown_async(const ResultCallback callback);



    /**
     * @brief Send command to shut down the drone components.
     *
     * This will shut down the autopilot, onboard computer, camera and gimbal.
     * This command should only be used when the autopilot is disarmed and autopilots commonly
     * reject it if they are not already ready to shut down.
     *
     * This function is blocking. See 'shutdown_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result shutdown() const;




    /**
     * @brief Send command to terminate the drone.
     *
     * This will run the terminate routine as configured on the drone (e.g. disarm and open the parachute).
     *
     * This function is non-blocking. See 'terminate' for the blocking counterpart.
     */
    void terminate_async(const ResultCallback callback);



    /**
     * @brief Send command to terminate the drone.
     *
     * This will run the terminate routine as configured on the drone (e.g. disarm and open the parachute).
     *
     * This function is blocking. See 'terminate_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result terminate() const;




    /**
     * @brief Send command to kill the drone.
     *
     * This will disarm a drone irrespective of whether it is landed or flying.
     * Note that the drone will fall out of the sky if this command is used while flying.
     *
     * This function is non-blocking. See 'kill' for the blocking counterpart.
     */
    void kill_async(const ResultCallback callback);



    /**
     * @brief Send command to kill the drone.
     *
     * This will disarm a drone irrespective of whether it is landed or flying.
     * Note that the drone will fall out of the sky if this command is used while flying.
     *
     * This function is blocking. See 'kill_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result kill() const;




    /**
     * @brief Send command to return to the launch (takeoff) position and land.
     *
     * This switches the drone into [Return mode](https://docs.px4.io/master/en/flight_modes/return.html) which
     * generally means it will rise up to a certain altitude to clear any obstacles before heading
     * back to the launch (takeoff) position and land there.
     *
     * This function is non-blocking. See 'return_to_launch' for the blocking counterpart.
     */
    void return_to_launch_async(const ResultCallback callback);



    /**
     * @brief Send command to return to the launch (takeoff) position and land.
     *
     * This switches the drone into [Return mode](https://docs.px4.io/master/en/flight_modes/return.html) which
     * generally means it will rise up to a certain altitude to clear any obstacles before heading
     * back to the launch (takeoff) position and land there.
     *
     * This function is blocking. See 'return_to_launch_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result return_to_launch() const;




    /**
     * @brief Send command to move the vehicle to a specific global position.
     *
     * The latitude and longitude are given in degrees (WGS84 frame) and the altitude
     * in meters AMSL (above mean sea level).
     *
     * The yaw angle is in degrees (frame is NED, 0 is North, positive is clockwise).
     *
     * This function is non-blocking. See 'goto_location' for the blocking counterpart.
     */
    void goto_location_async(double latitude_deg, double longitude_deg, float absolute_altitude_m, float yaw_deg, const ResultCallback callback);



    /**
     * @brief Send command to move the vehicle to a specific global position.
     *
     * The latitude and longitude are given in degrees (WGS84 frame) and the altitude
     * in meters AMSL (above mean sea level).
     *
     * The yaw angle is in degrees (frame is NED, 0 is North, positive is clockwise).
     *
     * This function is blocking. See 'goto_location_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result goto_location(double latitude_deg, double longitude_deg, float absolute_altitude_m, float yaw_deg) const;




    /**
     * @brief Send command do orbit to the drone.
     *
     * This will run the orbit routine with the given parameters.
     *
     * This function is non-blocking. See 'do_orbit' for the blocking counterpart.
     */
    void do_orbit_async(float radius_m, float velocity_ms, OrbitYawBehavior yaw_behavior, double latitude_deg, double longitude_deg, double absolute_altitude_m, const ResultCallback callback);



    /**
     * @brief Send command do orbit to the drone.
     *
     * This will run the orbit routine with the given parameters.
     *
     * This function is blocking. See 'do_orbit_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result do_orbit(float radius_m, float velocity_ms, OrbitYawBehavior yaw_behavior, double latitude_deg, double longitude_deg, double absolute_altitude_m) const;




    /**
     * @brief Send command to hold position (a.k.a. "Loiter").
     *
     * Sends a command to drone to change to Hold flight mode, causing the
     * vehicle to stop and maintain its current GPS position and altitude.
     *
     * Note: this command is specific to the PX4 Autopilot flight stack as
     * it implies a change to a PX4-specific mode.
     *
     * This function is non-blocking. See 'hold' for the blocking counterpart.
     */
    void hold_async(const ResultCallback callback);



    /**
     * @brief Send command to hold position (a.k.a. "Loiter").
     *
     * Sends a command to drone to change to Hold flight mode, causing the
     * vehicle to stop and maintain its current GPS position and altitude.
     *
     * Note: this command is specific to the PX4 Autopilot flight stack as
     * it implies a change to a PX4-specific mode.
     *
     * This function is blocking. See 'hold_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result hold() const;




    /**
     * @brief Send command to set the value of an actuator.
     *
     * Note that the index of the actuator starts at 1 and that the value goes from -1 to 1.
     *
     * This function is non-blocking. See 'set_actuator' for the blocking counterpart.
     */
    void set_actuator_async(int32_t index, float value, const ResultCallback callback);



    /**
     * @brief Send command to set the value of an actuator.
     *
     * Note that the index of the actuator starts at 1 and that the value goes from -1 to 1.
     *
     * This function is blocking. See 'set_actuator_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_actuator(int32_t index, float value) const;




    /**
     * @brief Send command to transition the drone to fixedwing.
     *
     * The associated action will only be executed for VTOL vehicles (on other vehicle types the
     * command will fail). The command will succeed if called when the vehicle
     * is already in fixedwing mode.
     *
     * This function is non-blocking. See 'transition_to_fixedwing' for the blocking counterpart.
     */
    void transition_to_fixedwing_async(const ResultCallback callback);



    /**
     * @brief Send command to transition the drone to fixedwing.
     *
     * The associated action will only be executed for VTOL vehicles (on other vehicle types the
     * command will fail). The command will succeed if called when the vehicle
     * is already in fixedwing mode.
     *
     * This function is blocking. See 'transition_to_fixedwing_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result transition_to_fixedwing() const;




    /**
     * @brief Send command to transition the drone to multicopter.
     *
     * The associated action will only be executed for VTOL vehicles (on other vehicle types the
     * command will fail). The command will succeed if called when the vehicle
     * is already in multicopter mode.
     *
     * This function is non-blocking. See 'transition_to_multicopter' for the blocking counterpart.
     */
    void transition_to_multicopter_async(const ResultCallback callback);



    /**
     * @brief Send command to transition the drone to multicopter.
     *
     * The associated action will only be executed for VTOL vehicles (on other vehicle types the
     * command will fail). The command will succeed if called when the vehicle
     * is already in multicopter mode.
     *
     * This function is blocking. See 'transition_to_multicopter_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result transition_to_multicopter() const;




    /**
    * @brief Callback type for get_takeoff_altitude_async.
    */
    using GetTakeoffAltitudeCallback = std::function<void(Result, float)>;

    /**
     * @brief Get the takeoff altitude (in meters above ground).
     *
     * This function is non-blocking. See 'get_takeoff_altitude' for the blocking counterpart.
     */
    void get_takeoff_altitude_async(const GetTakeoffAltitudeCallback callback);



    /**
     * @brief Get the takeoff altitude (in meters above ground).
     *
     * This function is blocking. See 'get_takeoff_altitude_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, float> get_takeoff_altitude() const;




    /**
     * @brief Set takeoff altitude (in meters above ground).
     *
     * This function is non-blocking. See 'set_takeoff_altitude' for the blocking counterpart.
     */
    void set_takeoff_altitude_async(float altitude, const ResultCallback callback);



    /**
     * @brief Set takeoff altitude (in meters above ground).
     *
     * This function is blocking. See 'set_takeoff_altitude_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_takeoff_altitude(float altitude) const;




    /**
    * @brief Callback type for get_return_to_launch_altitude_async.
    */
    using GetReturnToLaunchAltitudeCallback = std::function<void(Result, float)>;

    /**
     * @brief Get the return to launch minimum return altitude (in meters).
     *
     * This function is non-blocking. See 'get_return_to_launch_altitude' for the blocking counterpart.
     */
    void get_return_to_launch_altitude_async(const GetReturnToLaunchAltitudeCallback callback);



    /**
     * @brief Get the return to launch minimum return altitude (in meters).
     *
     * This function is blocking. See 'get_return_to_launch_altitude_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, float> get_return_to_launch_altitude() const;




    /**
     * @brief Set the return to launch minimum return altitude (in meters).
     *
     * This function is non-blocking. See 'set_return_to_launch_altitude' for the blocking counterpart.
     */
    void set_return_to_launch_altitude_async(float relative_altitude_m, const ResultCallback callback);



    /**
     * @brief Set the return to launch minimum return altitude (in meters).
     *
     * This function is blocking. See 'set_return_to_launch_altitude_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_return_to_launch_altitude(float relative_altitude_m) const;




    /**
     * @brief Set current speed.
     *
     * This will set the speed during a mission, reposition, and similar.
     * It is ephemeral, so not stored on the drone and does not survive a reboot.
     *
     * This function is non-blocking. See 'set_current_speed' for the blocking counterpart.
     */
    void set_current_speed_async(float speed_m_s, const ResultCallback callback);



    /**
     * @brief Set current speed.
     *
     * This will set the speed during a mission, reposition, and similar.
     * It is ephemeral, so not stored on the drone and does not survive a reboot.
     *
     * This function is blocking. See 'set_current_speed_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result set_current_speed(float speed_m_s) const;




    /**
     * @brief Copy constructor.
     */
    Action(const Action& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Action& operator=(const Action&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<ActionImpl> _impl;
};

} // namespace mavsdk