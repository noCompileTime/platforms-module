#pragma once

namespace core
{
    using seconds = std::chrono::duration<float>;

    using time_clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::high_resolution_clock::time_point;

    class PlatformTime
    {
    public:
        auto   init() -> void;
        auto update() -> void;

        static auto delta_time() -> float;
        static auto total_time() -> float;

    private:
        static constexpr auto max_delta_time { 0.06667f };

        inline static float _delta_time { };
        inline static float _total_time { };

        time_point   _start_time { };
        time_point _current_time { };
    };
}