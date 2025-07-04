// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/winch/winch.proto)

#include <iomanip>

#include "winch_impl.h"
#include "plugins/winch/winch.h"

namespace mavsdk {

using StatusFlags = Winch::StatusFlags;
using Status = Winch::Status;




Winch::Winch(System& system) : PluginBase(), _impl{std::make_unique<WinchImpl>(system)} {}

Winch::Winch(std::shared_ptr<System> system) : PluginBase(), _impl{std::make_unique<WinchImpl>(system)} {}


Winch::~Winch() {}



    
Winch::StatusHandle Winch::subscribe_status(const StatusCallback& callback)
{
    return _impl->subscribe_status(callback);
}

void Winch::unsubscribe_status(StatusHandle handle)
{
    _impl->unsubscribe_status(handle);
}
    




Winch::Status
Winch::status() const
{
    return _impl->status();
}



void Winch::relax_async(uint32_t instance, const ResultCallback callback)
{
    _impl->relax_async(instance, callback);
}



Winch::Result Winch::relax(uint32_t instance) const
{
    return _impl->relax(instance);
}



void Winch::relative_length_control_async(uint32_t instance, float length_m, float rate_m_s, const ResultCallback callback)
{
    _impl->relative_length_control_async(instance, length_m, rate_m_s, callback);
}



Winch::Result Winch::relative_length_control(uint32_t instance, float length_m, float rate_m_s) const
{
    return _impl->relative_length_control(instance, length_m, rate_m_s);
}



void Winch::rate_control_async(uint32_t instance, float rate_m_s, const ResultCallback callback)
{
    _impl->rate_control_async(instance, rate_m_s, callback);
}



Winch::Result Winch::rate_control(uint32_t instance, float rate_m_s) const
{
    return _impl->rate_control(instance, rate_m_s);
}



void Winch::lock_async(uint32_t instance, const ResultCallback callback)
{
    _impl->lock_async(instance, callback);
}



Winch::Result Winch::lock(uint32_t instance) const
{
    return _impl->lock(instance);
}



void Winch::deliver_async(uint32_t instance, const ResultCallback callback)
{
    _impl->deliver_async(instance, callback);
}



Winch::Result Winch::deliver(uint32_t instance) const
{
    return _impl->deliver(instance);
}



void Winch::hold_async(uint32_t instance, const ResultCallback callback)
{
    _impl->hold_async(instance, callback);
}



Winch::Result Winch::hold(uint32_t instance) const
{
    return _impl->hold(instance);
}



void Winch::retract_async(uint32_t instance, const ResultCallback callback)
{
    _impl->retract_async(instance, callback);
}



Winch::Result Winch::retract(uint32_t instance) const
{
    return _impl->retract(instance);
}



void Winch::load_line_async(uint32_t instance, const ResultCallback callback)
{
    _impl->load_line_async(instance, callback);
}



Winch::Result Winch::load_line(uint32_t instance) const
{
    return _impl->load_line(instance);
}



void Winch::abandon_line_async(uint32_t instance, const ResultCallback callback)
{
    _impl->abandon_line_async(instance, callback);
}



Winch::Result Winch::abandon_line(uint32_t instance) const
{
    return _impl->abandon_line(instance);
}



void Winch::load_payload_async(uint32_t instance, const ResultCallback callback)
{
    _impl->load_payload_async(instance, callback);
}



Winch::Result Winch::load_payload(uint32_t instance) const
{
    return _impl->load_payload(instance);
}



bool operator==(const Winch::StatusFlags& lhs, const Winch::StatusFlags& rhs)
{
    return
        (rhs.healthy == lhs.healthy) &&
        (rhs.fully_retracted == lhs.fully_retracted) &&
        (rhs.moving == lhs.moving) &&
        (rhs.clutch_engaged == lhs.clutch_engaged) &&
        (rhs.locked == lhs.locked) &&
        (rhs.dropping == lhs.dropping) &&
        (rhs.arresting == lhs.arresting) &&
        (rhs.ground_sense == lhs.ground_sense) &&
        (rhs.retracting == lhs.retracting) &&
        (rhs.redeliver == lhs.redeliver) &&
        (rhs.abandon_line == lhs.abandon_line) &&
        (rhs.locking == lhs.locking) &&
        (rhs.load_line == lhs.load_line) &&
        (rhs.load_payload == lhs.load_payload);
}

std::ostream& operator<<(std::ostream& str, Winch::StatusFlags const& status_flags)
{
    str << std::setprecision(15);
    str << "status_flags:" << '\n'
        << "{\n";
    str << "    healthy: " << status_flags.healthy << '\n';
    str << "    fully_retracted: " << status_flags.fully_retracted << '\n';
    str << "    moving: " << status_flags.moving << '\n';
    str << "    clutch_engaged: " << status_flags.clutch_engaged << '\n';
    str << "    locked: " << status_flags.locked << '\n';
    str << "    dropping: " << status_flags.dropping << '\n';
    str << "    arresting: " << status_flags.arresting << '\n';
    str << "    ground_sense: " << status_flags.ground_sense << '\n';
    str << "    retracting: " << status_flags.retracting << '\n';
    str << "    redeliver: " << status_flags.redeliver << '\n';
    str << "    abandon_line: " << status_flags.abandon_line << '\n';
    str << "    locking: " << status_flags.locking << '\n';
    str << "    load_line: " << status_flags.load_line << '\n';
    str << "    load_payload: " << status_flags.load_payload << '\n';
    str << '}';
    return str;
}


bool operator==(const Winch::Status& lhs, const Winch::Status& rhs)
{
    return
        (rhs.time_usec == lhs.time_usec) &&
        ((std::isnan(rhs.line_length_m) && std::isnan(lhs.line_length_m)) || rhs.line_length_m == lhs.line_length_m) &&
        ((std::isnan(rhs.speed_m_s) && std::isnan(lhs.speed_m_s)) || rhs.speed_m_s == lhs.speed_m_s) &&
        ((std::isnan(rhs.tension_kg) && std::isnan(lhs.tension_kg)) || rhs.tension_kg == lhs.tension_kg) &&
        ((std::isnan(rhs.voltage_v) && std::isnan(lhs.voltage_v)) || rhs.voltage_v == lhs.voltage_v) &&
        ((std::isnan(rhs.current_a) && std::isnan(lhs.current_a)) || rhs.current_a == lhs.current_a) &&
        (rhs.temperature_c == lhs.temperature_c) &&
        (rhs.status_flags == lhs.status_flags);
}

std::ostream& operator<<(std::ostream& str, Winch::Status const& status)
{
    str << std::setprecision(15);
    str << "status:" << '\n'
        << "{\n";
    str << "    time_usec: " << status.time_usec << '\n';
    str << "    line_length_m: " << status.line_length_m << '\n';
    str << "    speed_m_s: " << status.speed_m_s << '\n';
    str << "    tension_kg: " << status.tension_kg << '\n';
    str << "    voltage_v: " << status.voltage_v << '\n';
    str << "    current_a: " << status.current_a << '\n';
    str << "    temperature_c: " << status.temperature_c << '\n';
    str << "    status_flags: " << status.status_flags << '\n';
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, Winch::Result const& result)
{
    switch (result) {
        case Winch::Result::Unknown:
            return str << "Unknown";
        case Winch::Result::Success:
            return str << "Success";
        case Winch::Result::NoSystem:
            return str << "No System";
        case Winch::Result::Busy:
            return str << "Busy";
        case Winch::Result::Timeout:
            return str << "Timeout";
        case Winch::Result::Unsupported:
            return str << "Unsupported";
        case Winch::Result::Failed:
            return str << "Failed";
        default:
            return str << "Unknown";
    }
}



std::ostream& operator<<(std::ostream& str, Winch::WinchAction const& winch_action)
{
    switch (winch_action) {
        case Winch::WinchAction::Relaxed:
            return str << "Relaxed";
        case Winch::WinchAction::RelativeLengthControl:
            return str << "Relative Length Control";
        case Winch::WinchAction::RateControl:
            return str << "Rate Control";
        case Winch::WinchAction::Lock:
            return str << "Lock";
        case Winch::WinchAction::Deliver:
            return str << "Deliver";
        case Winch::WinchAction::Hold:
            return str << "Hold";
        case Winch::WinchAction::Retract:
            return str << "Retract";
        case Winch::WinchAction::LoadLine:
            return str << "Load Line";
        case Winch::WinchAction::AbandonLine:
            return str << "Abandon Line";
        case Winch::WinchAction::LoadPayload:
            return str << "Load Payload";
        default:
            return str << "Unknown";
    }
}


} // namespace mavsdk