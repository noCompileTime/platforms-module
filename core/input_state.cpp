#include "input_state.hpp"

namespace core
{
    auto InputState::update(const input::code code, const input::state state) noexcept -> void
    {
        const auto previous_state = std::exchange(_values.current [code],           state);
                                                  _values.previous[code] = previous_state;

        if (previous_state == input::state::released &&
                     state == input::state::pressed)
        {
            if (!std::ranges::contains(_changes, code))
            {
                _changes.emplace_back(code);
            }
        }
    }
}