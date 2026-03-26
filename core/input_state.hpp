#pragma once

namespace core
{
    class InputState
    {
    public:
        auto  update(input::code code, input::state state) noexcept -> void;

        [[nodiscard]] auto pressed(input::code code) const noexcept -> bool;

        [[nodiscard]] auto begin() const noexcept
        {
            return _changes.begin();
        }
        [[nodiscard]] auto   end() const noexcept
        {
            return _changes.end();
        }

        std::vector<input::code> _changes; // TODO make this private somehow

    private:
        std::unordered_map<input::code, input::state> _states;
    };
}