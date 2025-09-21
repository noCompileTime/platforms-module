#pragma once

namespace core
{
    class WindowManager
    {
    public:
        auto    init(const std::unique_ptr<base::PlatformFactory>& factory, const window::configuration& configuration) -> void;

        auto release()          const -> void;
        auto  update()          const -> void;

        auto  window()          const -> base::Window&;
        auto  window_context()  const -> base::WindowContext&;
        auto  window_events ()  const -> base::WindowEvents&;
        auto  window_input  ()  const -> base::WindowInput&;

    private:
        std::unique_ptr<base::Window>        _window;
        std::unique_ptr<base::WindowContext> _window_context;
        std::unique_ptr<base::WindowEvents>  _window_events;
        std::unique_ptr<base::WindowInput>   _window_input;
    };
}