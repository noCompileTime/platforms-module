#include "input_state.hpp"

namespace core
{
    auto InputState::pressed(const input::code code) const noexcept -> input::state
    {
        if (_active.contains(code))
        {
            return _active.at(code);
        }

        return input::state::unknown;
    }

    auto InputState::update(const input::code code, const input::state active) noexcept -> void
    {
        if (const auto before =  std::exchange(_active[code], active);
                       before == input::state::released &&
                       active == input::state::pressed)
        {
            if (!std::ranges::contains(_changes, code))
            {
                _changes.emplace_back(code);
            }
        }
    }
}