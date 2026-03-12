#pragma once

namespace core::window
{
    struct configuration
    {
        std::string_view title;

        int32_t    width   { };
        int32_t    height  { };
        int32_t    samples { }; // TODO separate what is for the context in another config?

        bool    fullscreen { };
        bool     maximized { };

        bool  srgb_buffer  { };
    };
}