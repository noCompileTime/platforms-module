#pragma once

#include "window.hpp"
#include "window_context.hpp"
#include "window_events.hpp"
#include "window_input.hpp"

#include "platform_functions.hpp"
#include "platform_monitor.hpp"

namespace core::base
{
    class PlatformFactory // TODO rename this to WindowFactory at some point
    {
    public: // TODO add some using std::unique_ptr<base::Window> Window_ptr here? to use them across the project
                 PlatformFactory() = default;
        virtual ~PlatformFactory() = default;

        [[nodiscard]] virtual auto create_window()             const noexcept -> std::unique_ptr<Window>            = 0;
        [[nodiscard]] virtual auto create_window_context()     const noexcept -> std::unique_ptr<WindowContext>     = 0; // TODO rename this without window?
        [[nodiscard]] virtual auto create_window_events()      const noexcept -> std::unique_ptr<WindowEvents>      = 0;
        [[nodiscard]] virtual auto create_window_input()       const noexcept -> std::unique_ptr<WindowInput>       = 0;

        [[nodiscard]] virtual auto create_platform_functions() const noexcept -> std::unique_ptr<PlatformFunctions> = 0;
        [[nodiscard]] virtual auto create_platform_monitor()   const noexcept -> std::unique_ptr<PlatformMonitor>   = 0; // TODO rename to monitor
    };
}