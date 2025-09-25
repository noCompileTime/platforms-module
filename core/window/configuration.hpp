#pragma once

namespace core::window
{
    struct configuration
    {
        std::string_view  title;

        int32_t     width   { };
        int32_t     height  { };
        int32_t     samples { };

        bool     fullscreen { };
        bool      maximized { };

        bool samples_buffer { };
        bool    srgb_buffer { };
    };
}