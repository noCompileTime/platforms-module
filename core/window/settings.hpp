#pragma once

namespace core::window
{
    struct settings
    {
        std::string_view title;

        std::int32_t width   { };
        std::int32_t height  { };
        std::int32_t samples { }; // TODO separate what is for the context in another config?

        bool fullscreen { };
        bool  maximized { };
        bool      debug { };
        bool       srgb { };
    };
}