#pragma once

namespace core
{
    class InputState
    {
    public:
        auto update(input::code code, input::state active) noexcept -> void;

        auto active(input::code code) const noexcept -> input::state;
        auto before(input::code code) const noexcept -> input::state;

        std::vector<input::code> _changes;

    private:
        std::unordered_map<input::code, input::state> _active;
        std::unordered_map<input::code, input::state> _before;
    };
}