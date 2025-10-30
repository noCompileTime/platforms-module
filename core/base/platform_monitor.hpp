#pragma once

namespace core::base
{
    class PlatformMonitor
    {
    public:
        virtual auto init() -> void = 0;

        virtual ~PlatformMonitor()  = default;

        int32_t  width  { }; // TODO add a getter for this? - just to be safe?
        int32_t  height { };
    };
}