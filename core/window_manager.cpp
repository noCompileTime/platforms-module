#include "window_manager.hpp"

namespace core
{
    auto WindowManager::init(const std::unique_ptr<base::PlatformFactory>& factory, const window::configuration& configuration) -> void
    {
        _window = factory->create_window();
        _window->create(configuration);

        _window_context = factory->create_window_context();
        _window_context->create(_window, configuration);

        _window_events = factory->create_window_events();
        _window_events->init(_window);

        _window_input = factory->create_window_input();
        _window_input->init(_window);
    }

    auto WindowManager::release() const -> void
    {
        _window_events->release(_window);
        _window_input ->release(_window);

        _window_context->destroy();
        _window        ->destroy();
    }

    auto WindowManager::update() const -> void
    {
        _window_events->update();
    }

    auto WindowManager::window() const -> base::Window&
    {
        return *_window;
    }

    auto WindowManager::window_context() const -> base::WindowContext&
    {
        return *_window_context;
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