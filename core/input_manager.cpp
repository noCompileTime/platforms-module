#include "input_manager.hpp"

namespace core
{
    auto InputManager::update() noexcept -> void
    {
        for (const auto& change : _input_state._state_changes)
        {
            _input_actions.execute(change);
        }

        _input_state._state_changes.clear(); // TODO maybe mark them as executed? to not make clear again and again?
    }

    auto InputManager::update(const input::code code, const input::state state) noexcept -> void // TODO move this into input_state?
    {
        const auto previous_state = std::exchange(_input_state._state_values.current [code],           state);
                                                  _input_state._state_values.previous[code] = previous_state;

        if (previous_state == input::state::released &&
                     state == input::state::pressed)
        {
            if (!std::ranges::contains(_input_state._state_changes, code))
            {
                _input_state._state_changes.emplace_back(code);
            }
        }
    }

    auto InputManager::pressed(const input::code code) const noexcept -> bool
    {
        // TODO move this into input_state
        const auto iterator  = _input_state._state_values.current.find(code);
            return iterator != _input_state._state_values.current.end() && iterator->second == input::state::pressed;
    }

    auto InputManager::input_actions() noexcept -> InputActions&
    {
        return _input_actions;
    }

    auto InputManager::input_state() noexcept -> InputState&
    {
        return _input_state;
    }
}