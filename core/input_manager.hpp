#pragma once

#include "input/states.hpp"
#include "input/states_changes.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto     update()                                     -> void;
        auto     update(input::code code, input::state state) -> void;

        auto is_pressed(input::code code) const -> bool;

        std::unordered_map<input::code, std::function<void()>> actions;

    private:
        input::states_changes _states_changes;
        input::states         _states;
    };
}