#include "platform_time.hpp"

namespace core
{
    auto PlatformTime::start() -> void
    {
          _start_time =
        _current_time = time_clock::now();
    }

    auto PlatformTime::tick() -> void
    {
           const auto current_time = time_clock::now();

        _elapsed_time = time_seconds(current_time -   _start_time).count();
          _delta_time = time_seconds(current_time - _current_time).count();

        _current_time = current_time;

        if (_delta_time > max_delta_time)
        {
            _delta_time = max_delta_time;
        }
    }

    auto PlatformTime::elapsed_time() -> float
    {
        return _elapsed_time;
    }

    auto PlatformTime::delta_time() -> float
    {
        return _delta_time;
    }
}