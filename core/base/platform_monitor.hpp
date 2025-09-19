#pragma once

namespace core::base
{
    class PlatformMonitor
    {
    public:
        virtual auto init() -> void = 0;

        virtual ~PlatformMonitor()  = default;

        int32_t width  { };
        int32_t height { };
    };
}