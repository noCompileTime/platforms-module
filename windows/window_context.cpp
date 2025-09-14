#include "window_context.hpp"

namespace windows
{
    auto WindowContext::create(const core::base::window_ptr& window) -> void
    {
        constexpr PIXELFORMATDESCRIPTOR pfd
        {
            .nSize   = sizeof(PIXELFORMATDESCRIPTOR),
            .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER
        };

        _hdc = GetDC(std::any_cast<HWND>(window->handle()));

        if (!SetPixelFormat(_hdc, ChoosePixelFormat(_hdc, &pfd), &pfd))
        {
            std::exit(core::window::status::pixel_format_not_available);
        }

        _hrc = wglCreateContext(_hdc);
                 wglMakeCurrent(_hdc, _hrc);
    }

    auto WindowContext::destroy() const -> void
    {
          wglMakeCurrent( nullptr, nullptr);
        wglDeleteContext(_hrc);
    }

    auto WindowContext::update() const -> void
    {
        SwapBuffers(_hdc);
    }
}