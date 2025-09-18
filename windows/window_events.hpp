#pragma once

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto    init(const core::base::window_ptr& window)       -> void override;
        auto release(const core::base::window_ptr& window) const -> void override;
        auto  update()                                     const -> void override;

        static auto process_any_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)  -> LRESULT;

    private:
        static auto process_btn_message(HWND hwnd, uint32_t code, core::input::state state) -> void;
        static auto process_key_message(HWND hwnd,   WPARAM code, core::input::state state) -> void;
    };
}