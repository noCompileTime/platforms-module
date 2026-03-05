#pragma once

namespace core::window
{
    struct input_callbacks // TODO add a callbacks folder and namespace?
    {
        std::function<void(input::code btn, input::state state)> on_btn_press { };
        std::function<void(input::code key, input::state state)> on_key_press { };

        std::function<void(int32_t x, int32_t y)>  on_mouse_motion { };
        std::function<void(int32_t    delta)>      on_mouse_scroll { };
    };
}