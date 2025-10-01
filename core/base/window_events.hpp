#pragma once

#include "window_ptr.hpp"

namespace core::base
{
    class WindowEvents
    {
    public:
        virtual auto     init(const window_ptr& window)       -> void = 0;
        virtual auto  release(const window_ptr& window) const -> void = 0;
        virtual auto   update()                         const -> void = 0;

        virtual ~WindowEvents()  = default;

        window::events_callbacks callbacks;
    };
}