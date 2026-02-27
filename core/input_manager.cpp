#include "input_manager.hpp"

namespace core
{
    auto InputManager::update() noexcept -> void
    {
        for (const auto& change : _state._changes)
        {
            _actions.execute(change);
        }

        _state._changes.clear(); // TODO maybe mark them as executed? to not make clear again and again?
    }

    auto InputManager::pressed(const input::code code) const noexcept -> bool
    {
        // TODO move this into input_state
        const auto iterator  = _state._values.current.find(code);
            return iterator != _state._values.current.end() && iterator->second == input::state::pressed;
    }

    auto InputManager::actions() noexcept -> InputActions&
    {
        return _actions;
    }

    auto InputManager::state() noexcept -> InputState&
    {
        return _state;
    }
}