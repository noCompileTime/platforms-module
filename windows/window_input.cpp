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
        codes[VK_LBUTTON] = core::input::codes::button_left;
        codes[VK_MBUTTON] = core::input::codes::button_middle;
        codes[VK_RBUTTON] = core::input::codes::button_right;

        codes[VK_ESCAPE]  = core::input::codes::key_escape;
        codes[VK_SPACE]   = core::input::codes::key_space;
        codes[VK_TAB]     = core::input::codes::key_tab;
    }
}