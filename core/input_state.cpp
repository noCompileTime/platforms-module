#include "input_state.hpp"

namespace core
{
    auto InputState::update(const input::code code, const input::state active) noexcept -> void
    {
        const auto before = std::exchange(_active[code] , active);
                                          _before[code] = before;

        if (active == input::state::pressed &&
            before == input::state::released)
        {
            if (!std::ranges::contains(_changes, code))
            {
                _changes.emplace_back(code);
            }
        }
    }

    auto InputState::active(const input::code code) const noexcept -> input::state
    {
        if (_active.contains(code))
        {
            return _active.at(code);
        }

        return input::state::unknown;
    }

    auto InputState::before(const input::code code) const noexcept -> input::state
    {
        if (_before.contains(code))
        {
            return _before.at(code);
        }

        return input::state::unknown;
    }
}