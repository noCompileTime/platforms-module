#pragma once

namespace core
{
    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    using time_seconds = std::chrono::duration<float>;

    class PlatformTime
    {
    public:
        auto   init() -> void;
        auto update() -> void;

        static auto delta_time() -> float;
        static auto total_time() -> float;

    private:
        static constexpr auto max_delta_time { 1.0 / 30.0f };

        inline static float  _delta_time { };
        inline static float  _total_time { };

        time_point   _start_time { };
        time_point _current_time { };
    };
}