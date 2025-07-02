#include <gmock/gmock.h>

#include "plugins/offboard/offboard.h"

namespace mavsdk {
namespace testing {

class MockOffboard {
public:
    MOCK_METHOD(Offboard::Result, start, (), (const));
    MOCK_METHOD(Offboard::Result, stop, (), (const));
    MOCK_METHOD(bool, is_active, (), (const));
    MOCK_METHOD(Offboard::Result, set_attitude, (Offboard::Attitude), (const));
    MOCK_METHOD(Offboard::Result, set_attitude, (Offboard::AttitudeQuaternion), (const));
    MOCK_METHOD(Offboard::Result, set_attitude_rate, (Offboard::AttitudeRate), (const));
    MOCK_METHOD(Offboard::Result, set_position_ned, (Offboard::PositionNedYaw), (const));
    MOCK_METHOD(Offboard::Result, set_position_global, (Offboard::PositionGlobalYaw), (const));
    MOCK_METHOD(Offboard::Result, set_velocity_body, (Offboard::VelocityBodyYawspeed), (const));
    MOCK_METHOD(Offboard::Result, set_velocity_ned, (Offboard::VelocityNedYaw), (const));
    MOCK_METHOD(Offboard::Result, set_position_velocity_ned, (Offboard::PositionNedYaw, Offboard::VelocityNedYaw), (const));
    MOCK_METHOD(Offboard::Result, set_position_velocity_acceleration_ned, (Offboard::PositionNedYaw, Offboard::VelocityNedYaw, Offboard::AccelerationNed), (const));
    MOCK_METHOD(Offboard::Result, set_acceleration_ned, (Offboard::AccelerationNed), (const));
    MOCK_METHOD(Offboard::Result, set_actuator_control, (Offboard::ActuatorControl), (const));
};

} // namespace testing
} // namespace mavsdk
