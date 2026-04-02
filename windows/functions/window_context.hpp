#pragma once

namespace windows::functions
{
     using PFNWGLCREATECONTEXTATTRIBSPROC = HGLRC(APIENTRY*)(HDC hdc, HGLRC share_context, const int32_t* attribs);
    inline PFNWGLCREATECONTEXTATTRIBSPROC wglCreateContextAttribs;

     using PFNWGLCHOOSEPIXELFORMATPROC = int32_t(APIENTRY*)(HDC hdc, const int32_t* int_attribs, const float* float_attribs, uint32_t max_formats, int32_t* formats, uint32_t* num_formats);
    inline PFNWGLCHOOSEPIXELFORMATPROC wglChoosePixelFormat;

     using PFNWGLSWAPINTERVALPROC = int32_t(APIENTRY*)(int32_t interval);
    inline PFNWGLSWAPINTERVALPROC wglSwapInterval;
}