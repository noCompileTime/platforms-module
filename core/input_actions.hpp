#pragma once

namespace core
{
    class InputActions
    {
    public:
        auto  assign(input::code code, const input::action& action) noexcept -> void;
        auto execute(input::code code)                              noexcept -> void;

    private:
        std::unordered_map<input::code, input::action> _actions;
    };
}