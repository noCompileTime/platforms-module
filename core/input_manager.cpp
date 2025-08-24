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
            if (const auto iterator  = actions.find(change);
                           iterator != actions.end())
            {
                iterator->second();
            }
        }

        _states_changes.clear();
    }

    auto InputManager::update(const input::code code, const input::state state) -> void
    {
       auto& previous_state =                _states.previous[code];
             previous_state =  std::exchange(_states.current [code], state);

        if (!previous_state && state)
        {
            if (!std::ranges::contains(_states_changes, code))
            {
                _states_changes.emplace_back(code);
            }
        }
    }

    auto InputManager::is_pressed(const input::code code) const -> bool
    {
        const auto iterator  = _states.current.find(code);
            return iterator != _states.current.end() && iterator->second == input::state::pressed;
    }
}