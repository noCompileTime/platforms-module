#pragma once

namespace core
{
    class InputState
    {
    public:
        input::state_changes _state_changes;
        input::state_values  _state_values;
    };
}