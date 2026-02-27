#pragma once

namespace core
{
    class InputState
    {
    public:
        auto update(input::code code, input::state active) noexcept -> void;

        std::unordered_map<input::code, input::state> _active;
        std::unordered_map<input::code, input::state> _before;

        std::vector<input::code> _changes;
    };
}