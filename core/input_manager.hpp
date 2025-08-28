#pragma once

#include "input_actions.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto    init(std::unique_ptr<InputActions> actions) -> void;

        auto  update()                                      -> void;
        auto  update(input::code code, input::state state)  -> void;

        auto    is_pressed(input::code code) const -> bool;
        auto input_actions()                 const -> InputActions&;

    private:
        std::unique_ptr<InputActions> _input_actions;

        input::states_changes _states_changes;
        input::states         _states;
    };
}