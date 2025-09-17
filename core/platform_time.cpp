#include "platform_time.hpp"

namespace core
{
    auto PlatformTime::init() -> void
    {
        _current_time = _start_time = time_clock::now();
    }

    auto PlatformTime::update() -> void
    {
        const auto current_time = time_clock::now();

        _total_time = seconds(current_time -   _start_time).count();
        _delta_time = seconds(current_time - _current_time).count();

        _current_time = current_time;

        if (_delta_time > max_delta_time)
        {
            _delta_time = max_delta_time;
        }
    }

    auto PlatformTime::delta_time() -> float
    {
        return _delta_time;
    }

    auto PlatformTime::total_time() -> float
    {
        return _total_time;
    }
}