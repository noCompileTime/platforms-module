#include "window_manager.hpp"

#include "platform_functions.hpp"

namespace core
{
    auto WindowManager::init(const std::unique_ptr<base::PlatformFactory>& factory, const window::settings& settings) noexcept -> void
    {
         PlatformFunctions::init(factory); // TODO remove when going to vulkan

        _window = factory->create_window();
        _window->create(settings);

        _context = factory->create_window_context();
        _context->create(window(), settings);

        _events = factory->create_window_events();
        _events->init(window());

        _input = factory->create_window_input();
        _input->init(window());
    }

    auto WindowManager::release() const noexcept -> void
    {
        _events->release(window());
        _input ->release(window());

        _context->destroy();
        _window->destroy();
    }

    auto WindowManager::update() const noexcept -> void
    {
        _events->update();
    }

    auto WindowManager::context() const noexcept -> base::WindowContext&
    {
        return *_context;
    }

    auto WindowManager::events() const noexcept -> base::WindowEvents&
    {
        return *_events;
    }

    auto WindowManager::input() const noexcept -> base::WindowInput&
    {
        return *_input;
    }

    auto WindowManager::window() const noexcept -> base::Window&
    {
        return *_window;
    }
}