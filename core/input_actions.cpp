#include "input_actions.hpp"

namespace core
{
    auto InputActions::set_action(const input::code code, const input::action& action) noexcept -> void
    {
        _actions[code] = action;
    }

    auto InputActions::execute(const input::code code) noexcept -> void
    {
        if (const auto iterator  = _actions.find(code);
                       iterator != _actions.end())
        {
            iterator->second();
        }
    }
}