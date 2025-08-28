#include "input_actions.hpp"

namespace core
{
    auto InputActions::add_action(const input::code code, const input::action& action) -> void
    {
        _actions[code] = action;
    }

    auto InputActions::execute(const input::code code) -> void
    {
        if (const auto iterator  = _actions.find(code);
                       iterator != _actions.end())
        {
            iterator->second();
        }
    }
}