#pragma once

#include "window.hpp"

namespace core::base
{
    class WindowContext
    {
    public:
        virtual auto    create(const std::unique_ptr<Window>& window) -> void = 0;

        virtual auto   destroy()   const -> void = 0;
        virtual auto    update()   const -> void = 0;

        virtual ~WindowContext() = default;
    };
}