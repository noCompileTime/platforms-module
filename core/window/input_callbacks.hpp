#pragma once

namespace core::window
{
    struct input_callbacks
    {
        std::function<void(input::code btn, input::state state)> on_btn_press { };
        std::function<void(input::code key, input::state state)> on_key_press { };
    };
}