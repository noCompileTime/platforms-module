#include "window_events.hpp"

#include "window_input.hpp"

namespace windows
{
    auto WindowEvents::init(const std::unique_ptr<core::base::Window>& window) -> void
    {
        SetProp(std::any_cast<HWND>(window->handle()), "events", this);
    }

    auto WindowEvents::release(const std::unique_ptr<core::base::Window>& window) -> void
    {
        RemoveProp(std::any_cast<HWND>(window->handle()), "events");
    }

    auto WindowEvents::update() const -> void
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
            case WM_CREATE:
            {
                SetThreadExecutionState(ES_DISPLAY_REQUIRED | ES_CONTINUOUS);

                break;
            }
            case WM_DESTROY:
            {
                SetThreadExecutionState(ES_CONTINUOUS);

                break;
            }
            case WM_CLOSE:
            {
                if (const auto window_events = static_cast<WindowEvents*>(GetProp(hwnd, "events"));
                               window_events && window_events->callbacks.close)
                {
                    window_events->callbacks.close();
                }

                return 0;
            }
            case WM_KEYUP:
            case WM_KEYDOWN:
            case WM_SYSKEYUP:
            case WM_SYSKEYDOWN:
            {
                if (const auto window_input = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                               window_input && window_input->callbacks.key_press)
                {
                    const auto state = (HIWORD(lparam) & KF_UP) == 0;
                    const auto   key =         wparam;

                    if (const auto it  = window_input->codes.find(key);
                                   it != window_input->codes.end())
                    {
                        window_input->callbacks.key_press(it->second, state);
                    }
                }

                break;
            }
            case WM_LBUTTONUP:
            case WM_MBUTTONUP:
            case WM_RBUTTONUP:
            {   // TODO maybe try to add a static function around here? because seems like very duplicate code
                if (const auto window_input = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                               window_input && window_input->callbacks.mouse_press)
                {
                    const auto button = msg == WM_LBUTTONUP ? VK_LBUTTON :
                                        msg == WM_MBUTTONUP ? VK_MBUTTON : VK_RBUTTON;

                    if (const auto it  = window_input->codes.find(button);
                                   it != window_input->codes.end())
                    {
                        window_input->callbacks.mouse_press(it->second, false);
                    }
                }
            }
            case WM_ERASEBKGND:
            {
                return 1;
            }
            default:
                break;
        }

        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}