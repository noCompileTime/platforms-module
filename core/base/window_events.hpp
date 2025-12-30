#pragma once

namespace core::base
{
    class WindowEvents
    {
    public:
                 WindowEvents() = default;
        virtual ~WindowEvents() = default;

        virtual auto     init(const std::unique_ptr<Window>& window)       noexcept -> void = 0;
        virtual auto  release(const std::unique_ptr<Window>& window) const noexcept -> void = 0;
        virtual auto   update()                                      const noexcept -> void = 0;

        window::events_callbacks callbacks;
    };
}