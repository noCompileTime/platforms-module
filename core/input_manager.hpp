#pragma once

#include "input/states.hpp"
#include "input/types.hpp"

#include "input_actions.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto     update()                                     -> void;
        auto     update(input::code code, input::state state) -> void;

        auto is_pressed(input::code code) const -> bool;

    private:
        InputActions _actions;

        input::states_changes _states_changes;
        input::states         _states;
    };
}