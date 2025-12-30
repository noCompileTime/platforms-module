#include "window.hpp"
#include "window_context.hpp"
#include "window_events.hpp"
#include "window_input.hpp"

#include "platform_factory.hpp"
#include "platform_functions.hpp"
#include "platform_monitor.hpp"

namespace windows
{
    auto PlatformFactory::create_window() const noexcept -> std::unique_ptr<core::base::Window>
    {
        return std::make_unique<Window>();
    }

    auto PlatformFactory::create_window_context() const noexcept -> std::unique_ptr<core::base::WindowContext>
    {
        return std::make_unique<WindowContext>();
    }

    auto PlatformFactory::create_window_events() const noexcept -> std::unique_ptr<core::base::WindowEvents>
    {
        return std::make_unique<WindowEvents>();
    }

    auto PlatformFactory::create_window_input() const noexcept -> std::unique_ptr<core::base::WindowInput>
    {
        return std::make_unique<WindowInput>();
    }

    auto PlatformFactory::create_platform_functions() const noexcept -> std::unique_ptr<core::base::PlatformFunctions>
    {
        return std::make_unique<PlatformFunctions>();
    }

    auto PlatformFactory::create_platform_monitor() const noexcept -> std::unique_ptr<core::base::PlatformMonitor>
    {
        return std::make_unique<PlatformMonitor>();
    }
}