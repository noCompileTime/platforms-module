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
        input::state_changes _state_changes;
        input::state_values  _state_values;

        InputActions _input_actions;
    };
}