#include "input_state.hpp"

namespace core
{
    auto InputState::update(const input::code code, const input::state new_state) noexcept -> void
    {
        if (const auto state = std::exchange(_states[code], new_state); state == input::state::released &&
                                                                    new_state == input::state::pressed)
        {
            if (!std::ranges::contains(_changes, code))
            {
                _changes.emplace_back(code);
            }
        }
    }

    auto InputState::pressed(const input::code code) const noexcept -> bool
    {
        const auto iterator  = _states.find(code);
            return iterator != _states.end() && iterator->second == input::state::pressed;
    }
}