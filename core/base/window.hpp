#pragma once

namespace core::base
{
    class Window
    {
    public:
        virtual auto  create() -> void = 0;
        virtual auto destroy() -> void = 0;

        virtual auto  handle() const -> std::any = 0;
        virtual auto    show() const -> void     = 0;

        virtual      ~Window() = default;
    };
}