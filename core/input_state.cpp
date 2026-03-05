#include "input_state.hpp"

namespace core
{
    auto InputState::update(const input::code code, const input::state state) noexcept -> void
    {
        if (const auto before =  std::exchange(_states[code], state);
                       before == input::state::released && state == input::state::pressed)
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