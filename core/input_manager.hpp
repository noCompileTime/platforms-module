#pragma once

#include "input/states.hpp"
#include "input/states_changes.hpp"

#include "input_actions.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto     update()                                     -> void;
        auto     update(input::code code, input::state state) -> void;

        auto is_pressed(input::code code) const -> bool;
        auto    actions()                       -> InputActions&;

    private:
        input::states_changes _states_changes;
        input::states         _states;

        InputActions _actions;
    };
}