#pragma once

#include "window_context.hpp"
#include "window_events.hpp"
#include "window_input.hpp"

#include "platform_functions.hpp"
#include "platform_monitor.hpp"

namespace core::base
{
    class PlatformFactory
    {
    public:
        virtual auto create_window            () const -> std::unique_ptr<Window>            = 0;
        virtual auto create_window_context    () const -> std::unique_ptr<WindowContext>     = 0;
        virtual auto create_window_events     () const -> std::unique_ptr<WindowEvents>      = 0;
        virtual auto create_window_input      () const -> std::unique_ptr<WindowInput>       = 0;

        virtual auto create_platform_monitor  () const -> std::unique_ptr<PlatformMonitor>   = 0;
        virtual auto create_platform_functions() const -> std::unique_ptr<PlatformFunctions> = 0;

        virtual ~PlatformFactory() = default;
    };
}