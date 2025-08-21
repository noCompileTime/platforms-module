#pragma once

namespace core::base
{
    struct window_input_callbacks
    {
        std::function<void(input::codes    key, input::state state)>    key_press { };
        std::function<void(input::codes button, input::state state)> button_press { };
    };
}