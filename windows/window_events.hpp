#pragma once

#include "core/base/window_events.hpp"
#include "core/base/window_input.hpp"

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto    init(const std::unique_ptr<core::base::Window>& window) -> void override;
        auto release(const std::unique_ptr<core::base::Window>& window) -> void override;
        auto  update()                                            const -> void override;

        static auto update(HWND hwnd, uint32_t msg, uintptr_t wparam, intptr_t lparam) -> intptr_t;

    private:
        static auto process_button_message(HWND hwnd,  uint32_t code, core::input::state state) -> void;
        static auto process_key_message   (HWND hwnd, uintptr_t code, core::input::state state) -> void;
    };
}