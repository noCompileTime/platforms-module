#pragma once

namespace core
{
    class WindowManager
    {
    public:
        auto  init(const std::unique_ptr<base::PlatformFactory>& factory, const window::configuration& configuration) noexcept -> void;

        auto release()           const noexcept -> void;
        auto  update()           const noexcept -> void;

        auto  window()           const noexcept -> base::Window&;
        auto  window_context()   const noexcept -> base::WindowContext&;
        auto  window_events ()   const noexcept -> base::WindowEvents&;
        auto  window_input  ()   const noexcept -> base::WindowInput&;

               WindowManager() = default;

    private:
        std::unique_ptr<base::WindowContext> _window_context;
        std::unique_ptr<base::WindowEvents>  _window_events;
        std::unique_ptr<base::WindowInput>   _window_input;
        std::unique_ptr<base::Window>        _window;
    };
}