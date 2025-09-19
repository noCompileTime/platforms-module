#pragma once

namespace core::window
{
    struct configuration
    {
        std::string_view  title;

        int32_t  width  { };
        int32_t  height { };

        bool fullscreen { };
        bool maximized  { };
    };
}