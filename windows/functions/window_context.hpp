#pragma once

namespace windows::functions
{
     using PFNWGLCREATECONTEXTATTRIBSPROC = auto(WINAPI*)(HDC hdc, HGLRC, const int32_t*)                                              -> HGLRC;
     using PFNWGLCHOOSEPIXELFORMATPROC    = auto(WINAPI*)(HDC hdc,        const int32_t*, const float*, uint32_t, int32_t*, uint32_t*) -> int32_t;
     using PFNWGLSWAPINTERVALPROC         = auto(WINAPI*)(int32_t)                                                                     -> int32_t;

    inline PFNWGLCREATECONTEXTATTRIBSPROC create_context_attribs;
    inline PFNWGLCHOOSEPIXELFORMATPROC    choose_pixel_format;
    inline PFNWGLSWAPINTERVALPROC         swap_interval;
}