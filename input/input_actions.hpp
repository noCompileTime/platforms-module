#pragma once

#include "types.hpp"

namespace core
{
    class InputActions
    {
    public:
        auto add_action(input::code code, const input::action& action) -> void;

        auto    execute(input::code code) -> void;

    private:
        input::actions _actions;
    };
}