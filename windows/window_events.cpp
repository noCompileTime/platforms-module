#include "window_events.hpp"

namespace windows
{
    auto WindowEvents::init(const std::any& handle) -> void
    {
        SetProp(std::any_cast<HWND>(handle), "events", this);
    }

    auto WindowEvents::release(const std::any& handle) -> void
    {
        RemoveProp(std::any_cast<HWND>(handle), "events");
    }

    auto WindowEvents::update() -> void
    {
        MSG msg;

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }

            TranslateMessage(&msg);
             DispatchMessage(&msg);
        }
    }

    auto WindowEvents::update(const HWND hwnd, const UINT msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        switch (msg)
        {
            case WM_CLOSE:
            {
                if (const auto window_events = static_cast<WindowEvents*>(GetProp(hwnd, "events"));
                               window_events->on_close)
                {
                    window_events->on_close();
                }

                return 0;
            }
            default:
                break;
        }

        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}