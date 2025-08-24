#pragma once

namespace core::input
{
    using action  = std::function<void()>;
    using actions = std::unordered_map<code, action>;

    using states_changes = std::vector<code>;
}