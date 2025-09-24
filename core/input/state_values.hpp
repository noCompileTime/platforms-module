#pragma once

#include "code.hpp"
#include "state.hpp"

namespace core::input
{
    struct states_values
    {
        std::unordered_map<code, state> current;
        std::unordered_map<code, state> previous;
    };
}