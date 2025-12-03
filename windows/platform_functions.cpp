#include "platform_functions.hpp"

namespace windows
{
    auto PlatformFunctions::init() -> void
    {
        SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    }

    auto PlatformFunctions::init_window_context_functions() -> void
    {
        functions::create_context_attribs = reinterpret_cast<functions::PFNWGLCREATECONTEXTATTRIBSPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
        functions::choose_pixel_format    = reinterpret_cast<functions::PFNWGLCHOOSEPIXELFORMATPROC>   (wglGetProcAddress("wglChoosePixelFormatARB"));
        functions::swap_interval          = reinterpret_cast<functions::PFNWGLSWAPINTERVALPROC>        (wglGetProcAddress("wglSwapIntervalEXT"));
    }
}