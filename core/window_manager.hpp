#pragma once

namespace core
{
    class WindowManager
    {
    public:
        WindowManager() = default;

        auto init(const std::unique_ptr<base::PlatformFactory>& factory, const window::settings& settings) noexcept -> void;

        auto release()  const noexcept -> void;
        auto  update()  const noexcept -> void;

        auto context()  const noexcept -> base::WindowContext&;
        auto  events()  const noexcept -> base::WindowEvents&;
        auto   input()  const noexcept -> base::WindowInput&;
        auto  window()  const noexcept -> base::Window&;

    private:
        std::unique_ptr<base::WindowContext> _context;
        std::unique_ptr<base::WindowEvents>  _events;
        std::unique_ptr<base::WindowInput>   _input;
        std::unique_ptr<base::Window>        _window;
    };
}