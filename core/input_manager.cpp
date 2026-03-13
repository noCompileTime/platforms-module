#include "input_manager.hpp"

namespace core
{
    auto InputManager::actions() noexcept -> InputActions&
    {
        return _actions;
    }

    auto InputManager::state() noexcept -> InputState&
    {
        return _state;
    }

    auto InputManager::update() noexcept -> void
    {
        for (const auto& change : _state)
        {
            _actions.execute(change);
        }

        _state._changes.clear(); // TODO maybe mark them as executed? to not make clear again and again?
    }
}