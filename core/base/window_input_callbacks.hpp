#pragma once

#include "core/input/codes.hpp"

namespace core::base
{
    struct window_input_callbacks
    {
        std::function<void(input::codes    key, bool state)>   key_press { };
        std::function<void(input::codes button, bool state)> mouse_press { };
    };
}