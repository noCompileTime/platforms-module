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

        auto  window()  const noexcept -> base::Window&;
        auto context()  const noexcept -> base::WindowContext&;
        auto  events()  const noexcept -> base::WindowEvents&;
        auto   input()  const noexcept -> base::WindowInput&;

    private:
        std::unique_ptr<base::Window>        _window;
        std::unique_ptr<base::WindowContext> _context;
        std::unique_ptr<base::WindowEvents>  _events;
        std::unique_ptr<base::WindowInput>   _input;
    };
}