#pragma once

#include "window.hpp"

namespace core::base
{
    class WindowEvents
    {
    public:
        virtual auto     init(const std::unique_ptr<Window>& window) -> void = 0;
        virtual auto  release(const std::unique_ptr<Window>& window) -> void = 0;
        virtual auto   update()                               const  -> void = 0;

        virtual ~WindowEvents()  = default;

        window::events_callbacks callbacks;
    };
}