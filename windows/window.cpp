#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::create(const core::window::configuration& configuration) noexcept -> void
    {
         register_class();
         register_style(configuration);

         constexpr auto frame_x = CW_USEDEFAULT;
         constexpr auto frame_y = CW_USEDEFAULT;
                   auto frame_w = configuration.width;
                   auto frame_h = configuration.height;

         if (!configuration.fullscreen)
         {
             RECT frame
             {
                 0, 0, configuration.width,
                       configuration.height
             };

             AdjustWindowRectEx(&frame, _style, FALSE, _extra);

             frame_w = frame.right  - frame.left;
             frame_h = frame.bottom - frame.top;
         }

        _hwnd = CreateWindowEx(_extra, MAKEINTATOM(_id), configuration.title.data(),
                               _style, frame_x, frame_y, frame_w, frame_h,  nullptr,  nullptr,
                                                            GetModuleHandle(nullptr), nullptr);
    }

    auto Window::destroy() const noexcept -> void
    {
        DestroyWindow(_hwnd);

        unregister_class();
    }

    auto Window::handle() const noexcept -> std::any
    {
        return _hwnd;
    }

    auto Window::title(const std::string_view title) const noexcept -> void
    {
        SetWindowText(_hwnd, title.data());
    }

    auto Window::show() const noexcept -> void
    {
        ShowWindow(_hwnd, SW_SHOW);
    }

    auto Window::register_class() noexcept -> void
    {
         const WNDCLASSEX classex
         {
             .cbSize        = sizeof(WNDCLASSEX),
             .style         = CS_OWNDC,  // CS_HREDRAW | CS_VREDRAW - we don't need to force window repaint on resize
             .lpfnWndProc   = WindowEvents::process_any_message,
             .hInstance     = GetModuleHandle(nullptr),
             .hIcon         = LoadIcon       (nullptr, IDI_APPLICATION),
             .hCursor       = LoadCursor     (nullptr, IDC_ARROW),
             .lpszClassName = "game_engine_window"
         };

        _id = RegisterClassEx(&classex);
    }

    auto Window::unregister_class() const noexcept -> void
    {
        UnregisterClass(MAKEINTATOM(_id), GetModuleHandle(nullptr));
    }

    auto Window::register_style(const core::window::configuration& configuration) noexcept -> void
    {
        if (configuration.fullscreen)
        {
            _style |= WS_POPUPWINDOW;
        }
        else
        {
            _style |= WS_OVERLAPPEDWINDOW;

            if (configuration.maximized)
            {
                _style |= WS_MAXIMIZE;
            }
        }
    }
}