#pragma once

#include "core/base/window_events.hpp"

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto    init(const std::unique_ptr<core::base::Window>& window) -> void override;
        auto release(const std::unique_ptr<core::base::Window>& window) -> void override;
        auto  update()                                            const -> void override;

        static auto update(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;
    };
}