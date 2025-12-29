#include "platform_functions.hpp"

namespace windows
{
    auto PlatformFunctions::init() -> void
    {
        SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    }

    auto PlatformFunctions::init_window_context_functions() -> void
    {
        functions::wglCreateContextAttribs = reinterpret_cast<functions::PFNWGLCREATECONTEXTATTRIBSPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
        functions::wglChoosePixelFormat    = reinterpret_cast<functions::PFNWGLCHOOSEPIXELFORMATPROC>   (wglGetProcAddress("wglChoosePixelFormatARB"));
        functions::wglSwapInterval         = reinterpret_cast<functions::PFNWGLSWAPINTERVALPROC>        (wglGetProcAddress("wglSwapIntervalEXT"));
    }
}