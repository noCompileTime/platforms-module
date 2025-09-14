#include "platforms_factory.hpp"

#include "window.hpp"
#include "window_context.hpp"
#include "window_events.hpp"
#include "window_input.hpp"

namespace windows
{
    auto PlatformsFactory::create_window() const -> std::unique_ptr<core::base::Window>
    {
        return std::make_unique<Window>();
    }

    auto PlatformsFactory::create_window_context() const -> std::unique_ptr<core::base::WindowContext>
    {
        return std::make_unique<WindowContext>();
    }

    auto PlatformsFactory::create_window_events() const -> std::unique_ptr<core::base::WindowEvents>
    {
        return std::make_unique<WindowEvents>();
    }

    auto PlatformsFactory::create_window_input() const -> std::unique_ptr<core::base::WindowInput>
    {
        return std::make_unique<WindowInput>();
    }
}