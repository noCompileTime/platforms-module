#pragma once

#include "window.hpp"
#include "window_events.hpp"

namespace core::base
{
    class PlatformsFactory
    {
    public:
        virtual auto create_window()        -> std::unique_ptr<Window>       = 0;
        virtual auto create_window_events() -> std::unique_ptr<WindowEvents> = 0;

        virtual ~PlatformsFactory() = default;
    };
}