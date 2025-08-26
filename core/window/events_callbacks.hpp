#pragma once

namespace core::window
{
    struct events_callbacks
    {
        std::function<void()> close { };
    };
}