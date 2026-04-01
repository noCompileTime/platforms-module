#include "window_context.hpp"

namespace windows
{
    auto WindowContext::create(const core::base::Window& window) noexcept -> void
    {
        constexpr PIXELFORMATDESCRIPTOR pfd
        {
            .nSize   = sizeof(PIXELFORMATDESCRIPTOR),
            .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER
        };

        _hdc = GetDC(std::any_cast<HWND>(window.handle()));

        if (!SetPixelFormat(_hdc, ChoosePixelFormat(_hdc, &pfd), &pfd))
        {
            std::exit(core::window::status::pixel_format_not_available);
        }

        _hrc = wglCreateContext(_hdc);
                 wglMakeCurrent(_hdc, _hrc);
    }

    auto WindowContext::create(const core::base::Window& window, const core::window::settings& settings) noexcept -> void
    {
        const int32_t pixel_attributes[]
        {
            constants::draw_to_window, 1,
            constants::support_opengl, 1,
            constants::double_buffer,  1,
            constants::acceleration,   constants::full_acceleration,
            constants::color_type,     constants::rgba,
            constants::color_bits,     32,
            constants::depth_bits,     24,
            constants::stencil_bits,    8,
            constants::srgb_buffer,     settings.srgb        ? 1 : 0,
            constants::samples_buffer,  settings.samples > 0 ? 1 : 0,
            constants::samples,         settings.samples,  0
        };

        _hdc = GetDC(std::any_cast<HWND>(window.handle()));

             int32_t format;
        if (uint32_t formats; functions::wglChoosePixelFormat(_hdc, pixel_attributes, nullptr, 1, &format, &formats) == 0 ||
                     formats == 0)
        {
            std::exit(core::window::status::pixel_format_not_found);
        }
                                                     PIXELFORMATDESCRIPTOR    pfd;
        if (DescribePixelFormat(_hdc, format, sizeof(PIXELFORMATDESCRIPTOR), &pfd) == 0)
        {
            std::exit(core::window::status::pixel_format_not_supported);
        }

        if (!SetPixelFormat(_hdc, format, &pfd))
        {
            std::exit(core::window::status::pixel_format_not_available);
        }

        const int32_t context_attributes[]
        {
            constants::major_version, 4,
            constants::minor_version, 6,
            constants::profile,                constants::core_profile,
            constants::flags, settings.debug ? constants::debug_bit :
                                               constants::no_error_bit, 0
        };
                             _hrc = functions::wglCreateContextAttribs(_hdc, nullptr, context_attributes);
        wglMakeCurrent(_hdc, _hrc);
    }

    auto WindowContext::destroy() const noexcept -> void
    {
          wglMakeCurrent( nullptr, nullptr);
        wglDeleteContext(_hrc);
    }

    auto WindowContext::update() const noexcept -> void
    {
        SwapBuffers(_hdc);
    }

    auto WindowContext::vsync(const int32_t interval) const noexcept -> void
    {
        functions::wglSwapInterval(interval);
    }
}