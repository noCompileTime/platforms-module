#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::create(const core::window::settings& settings) noexcept -> void
    {
         register_class();
         register_style(settings);

         constexpr auto frame_x = CW_USEDEFAULT;
         constexpr auto frame_y = CW_USEDEFAULT;
                   auto frame_w = settings.width;
                   auto frame_h = settings.height;

         if (!settings.fullscreen)
         {
             RECT frame
             {
                 0, 0, settings.width,
                       settings.height
             };

             AdjustWindowRectEx(&frame, _style, 0, _extra);

             frame_w = frame.right  - frame.left;
             frame_h = frame.bottom - frame.top;
         }

        _hwnd = CreateWindowEx(_extra, MAKEINTATOM(_id), settings.title.data(),
                               _style, frame_x, frame_y, frame_w, frame_h,  nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    }

    auto Window::destroy() const noexcept -> void
    {
        DestroyWindow(_hwnd);

        unregister_class();
    }

    auto Window::title(const std::string_view title) const noexcept -> void
    {
        SetWindowText(_hwnd, title.data());
    }

    auto Window::show() const noexcept -> void
    {
        ShowWindow(_hwnd, SW_SHOW);
    }

    auto Window::handle() const noexcept -> std::any
    {
        return _hwnd;
    }

    auto Window::register_class() noexcept -> void
    {
         const WNDCLASSEX classex
         {
             .cbSize        =  sizeof(WNDCLASSEX),
             .style         =  CS_OWNDC,  // CS_HREDRAW | CS_VREDRAW - we don't need to force window repaint on resize
             .lpfnWndProc   =  WindowEvents::process_any_message,
             .hInstance     =  GetModuleHandle(nullptr),
             .hIcon         =  LoadIcon       (nullptr, IDI_APPLICATION),
             .hCursor       =  LoadCursor     (nullptr, IDC_ARROW),
             .lpszClassName = "game_window"
         };

        _id = RegisterClassEx(&classex);
    }

    auto Window::unregister_class() const noexcept -> void
    {
        UnregisterClass(MAKEINTATOM(_id), GetModuleHandle(nullptr));
    }

    auto Window::register_style(const core::window::settings& settings) noexcept -> void
    {
        if (settings.fullscreen)
        {
            _style |= WS_POPUPWINDOW;
        }
        else
        {
            _style |= WS_OVERLAPPEDWINDOW;

            if (settings.maximized)
            {
                _style |= WS_MAXIMIZE;
            }
        }
    }
}