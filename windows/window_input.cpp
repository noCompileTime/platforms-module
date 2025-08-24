#include "window_input.hpp"

namespace windows
{
    auto WindowInput::init(const std::unique_ptr<core::base::Window>& window) -> void
    {
        SetProp(std::any_cast<HWND>(window->handle()), "input", this);

        init_codes();
    }

    auto WindowInput::release(const std::unique_ptr<core::base::Window>& window) -> void
    {
        RemoveProp(std::any_cast<HWND>(window->handle()), "input");
    }

    auto WindowInput::init_codes() -> void
    {
        codes[VK_LBUTTON] = core::input::code::btn_left;
        codes[VK_MBUTTON] = core::input::code::btn_middle;
        codes[VK_RBUTTON] = core::input::code::btn_right;

        codes[VK_ESCAPE]  = core::input::code::key_escape;
        codes[VK_SPACE]   = core::input::code::key_space;
        codes[VK_TAB]     = core::input::code::key_tab;

        codes['W']  = core::input::code::key_w;
        codes['A']  = core::input::code::key_a;
        codes['S']  = core::input::code::key_s;
        codes['D']  = core::input::code::key_d;
    }
}