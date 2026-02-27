#include "input_state.hpp"

namespace core
{
    auto InputState::active(const input::code code) const noexcept -> input::state
    {
        return _active.at(code);
    }

    auto InputState::before(const input::code code) const noexcept -> input::state
    {
        return _before.at(code);
    }

    auto InputState::update(const input::code code, const input::state active) noexcept -> void
    {
        const auto before = std::exchange(_active[code],  active);
                                          _before[code] = before;

        if (before == input::state::released && active == input::state::pressed)
        {
            if (!std::ranges::contains(_changes, code))
            {
                _changes.emplace_back(code);
            }
        }
    }
}