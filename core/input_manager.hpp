#pragma once

#include "input_actions.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto  update()                                     noexcept -> void;
        auto  update(input::code code, input::state state) noexcept -> void;

        auto pressed(input::code code) const noexcept -> bool;

        auto input_actions() noexcept -> InputActions&;

    private:
        input::states_changes _states_changes;
        input::states_values  _states_values;

        InputActions _input_actions;
    };
}