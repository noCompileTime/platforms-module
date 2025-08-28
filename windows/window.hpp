#pragma once

#include "core/base/window.hpp"

namespace windows
{
    class Window final : public core::base::Window
    {
    public:
        auto  create()       -> void override;
        auto destroy()       -> void override;

        auto  handle() const -> std::any override;
        auto    show() const -> void     override;

    private:
        auto   register_class()       -> void;
        auto unregister_class() const -> void;

        uint32_t _style { WS_CLIPSIBLINGS | WS_CLIPCHILDREN };
        uint32_t _extra { WS_EX_APPWINDOW };

        HWND _hwnd { };
        ATOM _id   { };
    };
}