#include "input_manager.hpp"

namespace core
{
    auto InputManager::update() -> void
    {
        if (_states_changes.empty())
        {
            return;
        }

        for (const auto& change : _states_changes)
        {
            _input_actions.execute(change);
        }

        _states_changes.clear();
    }

    auto InputManager::update(const input::code code, const input::state state) -> void
    {
      auto& previous_state  =               _states_values.previous[code];
            previous_state  = std::exchange(_states_values.current [code], state);

        if (previous_state == input::state::released &&
                     state == input::state::pressed)
        {
            if (std::ranges::contains(_states_changes, code) == false)
            {
                _states_changes.emplace_back(code);
            }
        }
    }

    auto InputManager::pressed(const input::code code) const -> bool
    {
        const auto iterator  = _states_values.current.find(code);
            return iterator != _states_values.current.end() && iterator->second == input::state::pressed;
    }

    auto InputManager::input_actions() -> InputActions&
    {
        return _input_actions;
    }
}