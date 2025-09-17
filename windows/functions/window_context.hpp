#pragma once

namespace windows::functions
{
    using PFNWGLCREATECONTEXTATTRIBSPROC = auto(WINAPI*)(HDC hdc, HGLRC shared_context, const int32_t* attrib_list) -> HGLRC;
    using PFNWGLCHOOSEPIXELFORMATPROC    = auto(WINAPI*)(HDC hdc, const int32_t* attrib_list, const float* attrib_weights, uint32_t max_formats , int32_t* format_list, uint32_t* num_formats) -> int32_t;
    using PFNWGLSWAPINTERVALPROC         = auto(WINAPI*)(int32_t interval) -> int32_t;

    inline PFNWGLCREATECONTEXTATTRIBSPROC create_context_attribs;
    inline PFNWGLCHOOSEPIXELFORMATPROC    choose_pixel_format;
    inline PFNWGLSWAPINTERVALPROC         swap_interval;
}