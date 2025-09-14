#pragma once

#include <any>

namespace core::base
{
    class Window
    {
    public:
        virtual auto  create()       -> void = 0;
        virtual auto destroy() const -> void = 0;

        virtual auto  handle() const -> std::any = 0;
        virtual auto    show() const -> void     = 0;

        virtual      ~Window() = default;
    };
}