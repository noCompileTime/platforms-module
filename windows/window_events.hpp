#pragma once

#include "core/base/window_events.hpp"

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto    init(const std::any& handle) -> void override;
        auto release(const std::any& handle) -> void override;
        auto update()                        -> void override;

        static auto update(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;
    };
}