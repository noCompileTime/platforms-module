#pragma once

namespace core::base
{
    class WindowContext
    {
    public:
                 WindowContext() = default;
        virtual ~WindowContext() = default;

        virtual auto  create(const Window& window)                                   noexcept -> void = 0;
        virtual auto  create(const Window& window, const window::settings& settings) noexcept -> void = 0;

        virtual auto destroy()                      const noexcept -> void = 0;
        virtual auto  update()                      const noexcept -> void = 0;
        virtual auto   vsync(std::int32_t interval) const noexcept -> void = 0;
    };
}