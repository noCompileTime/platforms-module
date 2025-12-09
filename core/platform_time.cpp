#include "platform_time.hpp"

namespace core
{
    auto PlatformTime::start() noexcept -> void
    {
          _start_t =
        _current_t = time_clock::now();
    }

    auto PlatformTime::tick() noexcept -> void
    {
            const auto current_t = time_clock::now();

          _elapsed_t = time_seconds(current_t -   _start_t).count();
            _delta_t = time_seconds(current_t - _current_t).count();

          _current_t = current_t;

        if (_delta_t > max_delta_t)
        {
            _delta_t = max_delta_t;
        }
    }

    auto PlatformTime::elapsed() noexcept -> float
    {
        return _elapsed_t;
    }

    auto PlatformTime::delta() noexcept -> float
    {
        return _delta_t;
    }
}