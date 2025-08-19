#pragma once

namespace core::base
{
    struct window_events_callbacks
    {
        std::function<void()> close { };
    };
}