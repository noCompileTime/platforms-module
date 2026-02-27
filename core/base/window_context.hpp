#pragma once

namespace core::base
{
    class WindowContext
    {
    public:
                 WindowContext() = default;
        virtual ~WindowContext() = default;

        virtual auto  create(const std::unique_ptr<Window>& window)                                             noexcept -> void = 0;
        virtual auto  create(const std::unique_ptr<Window>& window, const window::configuration& configuration) noexcept -> void = 0;

        virtual auto destroy()                 const noexcept -> void = 0;
        virtual auto  update()                 const noexcept -> void = 0;
        virtual auto    sync(int32_t interval) const noexcept -> void = 0;
    };
}