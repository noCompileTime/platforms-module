#include "window_events.hpp"
#include "window_input.hpp"

#include "window_input.hpp"

namespace windows
{
    auto WindowEvents::init(const core::base::window_ptr& window) -> void
    {
        SetProp(std::any_cast<HWND>(window->handle()), "events", this);
    }

    auto WindowEvents::release(const core::base::window_ptr& window) const -> void
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

    auto WindowEvents::process_any_message(const HWND hwnd, const UINT msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        switch (msg)
        {
            case WM_LBUTTONDOWN:
            case WM_RBUTTONDOWN:
            case WM_MBUTTONDOWN:
            {
                const auto code = msg == WM_LBUTTONDOWN ? VK_LBUTTON :
                                  msg == WM_RBUTTONDOWN ? VK_RBUTTON : VK_MBUTTON;

                process_btn_message(hwnd, code, core::input::state::pressed);

                break;
            }
            case WM_LBUTTONUP:
            case WM_RBUTTONUP:
            case WM_MBUTTONUP:
            {
                const auto code = msg == WM_LBUTTONUP ? VK_LBUTTON :
                                  msg == WM_RBUTTONUP ? VK_RBUTTON : VK_MBUTTON;

                process_btn_message(hwnd, code, core::input::state::released);

                break;
            }
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
            {
                if ((lparam & 1 << 30) == 0)
                {
                    process_key_message(hwnd, wparam, core::input::state::pressed);
                }

                break;
            }
            case WM_KEYUP:
            case WM_SYSKEYUP:
            {
                process_key_message(hwnd, wparam, core::input::state::released);

                break;
            }
            case WM_MOUSEMOVE:
            {
                if (const auto window_input  = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                               window_input && window_input->callbacks.on_mouse_motion)
                {
                    const auto x = LOWORD(lparam);
                    const auto y = HIWORD(lparam);

                    window_input->callbacks.on_mouse_motion(x, y);
                }

                break;
            }
            case WM_MOUSEWHEEL:
            {
                if (const auto window_input  = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                               window_input && window_input->callbacks.on_mouse_scroll)
                {
                    const auto delta = GET_WHEEL_DELTA_WPARAM(wparam) / WHEEL_DELTA;

                        window_input->callbacks.on_mouse_scroll(delta);
                }
            }
            case WM_CREATE:
            {
                SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED);

                break;
            }
            case WM_DESTROY:
            {
                SetThreadExecutionState(ES_CONTINUOUS);

                break;
            }
            case WM_CLOSE:
            {
                if (const auto window_events  = static_cast<WindowEvents*>(GetProp(hwnd, "events"));
                               window_events && window_events->callbacks.on_close)
                {
                    window_events->callbacks.on_close();
                }

                return 0;
            }
            case WM_SIZE:
            {
                if (const auto window_events  = static_cast<WindowEvents*>(GetProp(hwnd, "events"));
                               window_events && window_events->callbacks.on_resize)
                {
                    const auto width  =  LOWORD(lparam);
                    const auto height =  HIWORD(lparam);

                    window_events->callbacks.on_resize(width, height);
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

    auto WindowEvents::process_btn_message(const HWND hwnd, const uint32_t code, const core::input::state state) -> void
    {
        if (const auto window_input  = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                       window_input && window_input->callbacks.on_btn_press)
        {
            if (const auto iterator  = window_input->codes.find(code);
                           iterator != window_input->codes.end())
            {
                window_input->callbacks.on_btn_press(iterator->second, state);
            }
        }
    }

    auto WindowEvents::process_key_message(const HWND hwnd, const WPARAM code, const core::input::state state) -> void
    {
        if (const auto window_input  = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                       window_input && window_input->callbacks.on_key_press)
        {
            if (const auto iterator  = window_input->codes.find(code);
                           iterator != window_input->codes.end())
            {
                window_input->callbacks.on_key_press(iterator->second, state);
            }
        }
    }
}