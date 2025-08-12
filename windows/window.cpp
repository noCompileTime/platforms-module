#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::create() -> void
    {
        _style |= WS_OVERLAPPEDWINDOW;

        const auto instance = GetModuleHandle(nullptr);

        const WNDCLASSEX classex
        {
            .cbSize        = sizeof(WNDCLASSEX),
            .style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
            .lpfnWndProc   = WindowEvents::update,
            .hInstance     = instance,
            .hIcon         = LoadIcon  (nullptr, IDI_APPLICATION),
            .hCursor       = LoadCursor(nullptr, IDC_ARROW),
            .lpszClassName = "window"
        };

        _id = RegisterClassEx(&classex);

        _hwnd = CreateWindowEx(_extra, MAKEINTATOM(_id), "Platforms Framework", _style, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, nullptr, nullptr, instance, nullptr);
    }

    auto Window::destroy() -> void
    {
        DestroyWindow(_hwnd);
    }

    auto Window::handle() const -> std::any
    {
        return _hwnd;
    }

    auto Window::show() const -> void
    {
        ShowWindow(_hwnd, SW_SHOW);
    }
}