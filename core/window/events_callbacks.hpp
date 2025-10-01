#pragma once

namespace core::window
{
    struct events_callbacks
    {
        std::function<void(int32_t width, int32_t height)> on_resize { };
        std::function<void()>                              on_close  { };
    };
}