#pragma once

#include "window_context.hpp"
#include "window_events.hpp"
#include "window_input.hpp"

namespace core::base
{
    class PlatformsFactory
    {
    public:
        virtual auto create_window()         const -> std::unique_ptr<Window>        = 0;
        virtual auto create_window_context() const -> std::unique_ptr<WindowContext> = 0;
        virtual auto create_window_events () const -> std::unique_ptr<WindowEvents>  = 0;
        virtual auto create_window_input  () const -> std::unique_ptr<WindowInput>   = 0;

        virtual  ~PlatformsFactory() = default;
    };
}