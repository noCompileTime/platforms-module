#pragma once

namespace core::base
{
    class PlatformMonitor // TODO rename to WindowMonitor at some point
    {
    public:
                 PlatformMonitor() = default;
        virtual ~PlatformMonitor() = default;

        virtual auto init() noexcept -> void = 0;

        [[nodiscard, maybe_unused]] auto width() const noexcept
        {
            return  _width;
        }

        [[nodiscard, maybe_unused]] auto height() const noexcept
        {
            return _height;
        }

    protected:
        int32_t _width;
        int32_t _height;
    };
}