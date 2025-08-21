#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::create() -> void
    {
         register_class();

        _style |= WS_OVERLAPPEDWINDOW;

        _hwnd = CreateWindowEx(_extra, MAKEINTATOM(_id), "Platforms Framework", _style, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    }

    auto Window::destroy() -> void
    {
        DestroyWindow(_hwnd);

        unregister_class();
    }

    auto Window::handle() const -> std::any
    {
        return _hwnd;
    }

    auto Window::show() const -> void
    {
        ShowWindow(_hwnd, SW_SHOW);
    }

    auto Window::register_class() -> void
    {
        const WNDCLASSEX classex
        {
            .cbSize        = sizeof(WNDCLASSEX),
            .style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
            .lpfnWndProc   = WindowEvents::process_message,
            .hInstance     = GetModuleHandle(nullptr),
            .hIcon         = LoadIcon       (nullptr, IDI_APPLICATION),
            .hCursor       = LoadCursor     (nullptr, IDC_ARROW),
            .lpszClassName = "window"
        };

        _id = RegisterClassEx(&classex);
    }

    auto Window::unregister_class() const -> void
    {
        UnregisterClass(MAKEINTATOM(_id), GetModuleHandle(nullptr));
    }
}