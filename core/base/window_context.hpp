#pragma once

#include "window.hpp"

namespace core::base
{
    class WindowContext
    {
    public:
        virtual auto    create(const window_ptr& window, int32_t samples) -> void = 0;
        virtual auto    create(const window_ptr& window)                  -> void = 0;
        virtual auto   destroy()                                    const -> void = 0;
        virtual auto    update()                                    const -> void = 0;

        virtual ~WindowContext() = default;
    };
}