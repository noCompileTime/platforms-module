#pragma once

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto    init(const std::unique_ptr<core::base::Window>& window)       noexcept -> void override;
        auto release(const std::unique_ptr<core::base::Window>& window) const noexcept -> void override;
        auto  update()                                                  const noexcept -> void override;

        static auto process_any_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)  -> LRESULT;

    private:
        static auto process_btn_message(HWND hwnd, uint32_t code, core::input::state state) -> void;
        static auto process_key_message(HWND hwnd, uint32_t code, core::input::state state) -> void;

        static constexpr auto events_prop_key = "events";
        static constexpr auto  input_prop_key = "input";
    };
}