#include "window_input.hpp"

namespace windows
{
    auto WindowInput::init(const core::base::Window& window) noexcept -> void
    {
        init_codes();

        SetProp(std::any_cast<HWND>(window.handle()), "input", this);
    }

    auto WindowInput::release(const core::base::Window& window) const noexcept -> void
    {
        RemoveProp(std::any_cast<HWND>(window.handle()), "input");
    }

    auto WindowInput::init_codes() noexcept -> void
    {
        codes[VK_LBUTTON] = core::input::code::btn_left;
        codes[VK_MBUTTON] = core::input::code::btn_middle;
        codes[VK_RBUTTON] = core::input::code::btn_right;

        codes[VK_UP]      = core::input::code::key_up;
        codes[VK_DOWN]    = core::input::code::key_down;
        codes[VK_LEFT]    = core::input::code::key_left;
        codes[VK_RIGHT]   = core::input::code::key_right;

        codes[VK_ESCAPE]  = core::input::code::key_escape;
        codes[VK_SPACE]   = core::input::code::key_space;
        codes[VK_TAB]     = core::input::code::key_tab;

        codes['W'] = core::input::code::key_w;
        codes['A'] = core::input::code::key_a;
        codes['S'] = core::input::code::key_s;
        codes['D'] = core::input::code::key_d;
    }
}