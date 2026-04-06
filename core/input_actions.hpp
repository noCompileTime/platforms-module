#pragma once

//#include "input/action.hpp" // TODO leave this here? and remove them from pch?
//#include "input/code.hpp"

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