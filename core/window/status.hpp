#pragma once

namespace core::window
{
    enum status // TODO move this into some platform_status? and be called from a callback or something?
    {
        pixel_format_not_available,
        pixel_format_not_supported,
        pixel_format_not_found
    };
}