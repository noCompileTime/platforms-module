#include "window_manager.hpp"

#include "windows/platforms_factory.hpp"

namespace core
{
    auto WindowManager::init() -> void
    {
         const auto factory = std::make_unique<windows::PlatformsFactory>();

        _window = factory->create_window();
        _window->create();

        _window_events = factory->create_window_events();
        _window_events->init(_window);

        _window_input = factory->create_window_input();
        _window_input->init(_window);
    }

    auto WindowManager::release() const -> void
    {
        _window_events->release(_window);
        _window_input ->release(_window);

        _window->destroy();
    }

    auto WindowManager::window() const -> base::Window&
    {
        return *_window;
    }

    auto WindowManager::window_events() const -> base::WindowEvents&
    {
        return *_window_events;
    }

    auto WindowManager::window_input() const -> base::WindowInput&
    {
        return *_window_input;
    }
}