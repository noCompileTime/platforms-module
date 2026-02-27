#pragma once

namespace core
{
    class InputState
    {
    public:
        auto update(input::code code, input::state state) noexcept -> void;

        input::state_changes _changes;
        input::state_values  _values;
    };
}