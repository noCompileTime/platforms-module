#pragma once

namespace core
{
    class InputActions
    {
    public:
        auto set_action(input::code code, const input::action& action) -> void;
        auto    execute(input::code code)                              -> void;

    private:
        std::unordered_map<input::code, input::action> _actions;
    };
}