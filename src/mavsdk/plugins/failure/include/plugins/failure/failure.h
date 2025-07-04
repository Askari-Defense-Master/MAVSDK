// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/failure/failure.proto)

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


class System;class FailureImpl;

/**
 * @brief Inject failures into system to test failsafes.
 */
class Failure : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto failure = Failure(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Failure(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto failure = Failure(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Failure(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Failure() override;


    /**
     * @brief A failure unit.
     */
    enum class FailureUnit {
        SensorGyro, /**< @brief Gyro. */
        SensorAccel, /**< @brief Accelerometer. */
        SensorMag, /**< @brief Magnetometer. */
        SensorBaro, /**< @brief Barometer. */
        SensorGps, /**< @brief GPS. */
        SensorOpticalFlow, /**< @brief Optical flow. */
        SensorVio, /**< @brief Visual inertial odometry. */
        SensorDistanceSensor, /**< @brief Distance sensor. */
        SensorAirspeed, /**< @brief Airspeed. */
        SystemBattery, /**< @brief Battery. */
        SystemMotor, /**< @brief Motor. */
        SystemServo, /**< @brief Servo. */
        SystemAvoidance, /**< @brief Avoidance. */
        SystemRcSignal, /**< @brief RC signal. */
        SystemMavlinkSignal, /**< @brief MAVLink signal. */
    };

    /**
     * @brief Stream operator to print information about a `Failure::FailureUnit`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Failure::FailureUnit const& failure_unit);

    /**
     * @brief A failure type
     */
    enum class FailureType {
        Ok, /**< @brief No failure injected, used to reset a previous failure. */
        Off, /**< @brief Sets unit off, so completely non-responsive. */
        Stuck, /**< @brief Unit is stuck e.g. keeps reporting the same value. */
        Garbage, /**< @brief Unit is reporting complete garbage. */
        Wrong, /**< @brief Unit is consistently wrong. */
        Slow, /**< @brief Unit is slow, so e.g. reporting at slower than expected rate. */
        Delayed, /**< @brief Data of unit is delayed in time. */
        Intermittent, /**< @brief Unit is sometimes working, sometimes not. */
    };

    /**
     * @brief Stream operator to print information about a `Failure::FailureType`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Failure::FailureType const& failure_type);





    /**
     * @brief Possible results returned for failure requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        Unsupported, /**< @brief Failure not supported. */
        Denied, /**< @brief Failure injection denied. */
        Disabled, /**< @brief Failure injection is disabled. */
        Timeout, /**< @brief Request timed out. */
    };

    /**
     * @brief Stream operator to print information about a `Failure::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Failure::Result const& result);



    /**
     * @brief Callback type for asynchronous Failure calls.
     */
    using ResultCallback = std::function<void(Result)>;






    /**
     * @brief Injects a failure.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result inject(FailureUnit failure_unit, FailureType failure_type, int32_t instance) const;




    /**
     * @brief Copy constructor.
     */
    Failure(const Failure& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Failure& operator=(const Failure&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<FailureImpl> _impl;
};

} // namespace mavsdk