#pragma once

namespace core::base
{
    class PlatformMonitor
    {
    public:
                 PlatformMonitor() = default;
        virtual ~PlatformMonitor() = default;

        virtual auto init() noexcept -> void = 0;

        auto  width() const noexcept -> int32_t
        {
            return _width;
        }

        auto height() const noexcept -> int32_t
        {
            return _height;
        }

    protected:
        int32_t _width;
        int32_t _height;
    };
}