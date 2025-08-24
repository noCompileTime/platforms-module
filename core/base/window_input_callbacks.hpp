#pragma once

namespace core::base
{
    struct window_input_callbacks
    {
        std::function<void(input::code btn, input::state state)> btn_press { };
        std::function<void(input::code key, input::state state)> key_press { };
    };
}