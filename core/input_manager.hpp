#pragma once

#include "input_actions.hpp"
#include "input_state.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto  update()                                     noexcept -> void;
        auto  update(input::code code, input::state state) noexcept -> void; // TODO rename this to update_state?

        auto pressed(input::code code)   const noexcept -> bool;

        auto input_actions() noexcept -> InputActions&;
        auto input_state()   noexcept -> InputState&;

    private:
        InputActions _input_actions;
        InputState   _input_state;
    };
}