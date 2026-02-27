#pragma once

#include "input_actions.hpp"
#include "input_state.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto pressed(input::code code) const noexcept -> bool;
        auto  update()                       noexcept -> void;

        auto actions() noexcept -> InputActions&;
        auto   state() noexcept -> InputState&;

    private:
        InputActions _actions;
        InputState   _state;
    };
}