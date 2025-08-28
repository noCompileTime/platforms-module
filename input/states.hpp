#pragma once

namespace core::input
{
    struct states
    {
        std::unordered_map<code, state> current;
        std::unordered_map<code, state> previous;
    };
}