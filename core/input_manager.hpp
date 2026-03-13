#pragma once

#include "input_actions.hpp"
#include "input_state.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto actions() noexcept -> InputActions&;
        auto   state() noexcept -> InputState&;

        auto  update() noexcept -> void;

    private:
        InputActions _actions;
        InputState   _state;
    };
}