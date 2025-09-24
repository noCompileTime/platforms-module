#pragma once

#include "input_actions.hpp"
#include "input_mouse.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto  update()                                     -> void;
        auto  update(input::code code, input::state state) -> void;

        auto pressed(input::code code) const -> bool;

        auto input_actions()  -> InputActions&;
        auto input_mouse  ()  -> InputMouse&;

    private:
        input::states_changes _states_changes;
        input::states_values  _states_values;

        InputActions    _input_actions;
        InputMouse      _input_mouse;
    };
}