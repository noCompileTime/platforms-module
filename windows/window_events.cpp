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

    auto WindowEvents::process_message(const HWND hwnd, const uint32_t msg, const uintptr_t wparam, const intptr_t lparam) -> intptr_t
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
            case WM_LBUTTONDOWN:
            case WM_RBUTTONDOWN:
            case WM_MBUTTONDOWN:
            {
                const auto code = msg == WM_LBUTTONDOWN ? VK_LBUTTON :
                                  msg == WM_RBUTTONDOWN ? VK_RBUTTON : VK_MBUTTON;

                process_btn_message(hwnd, code, core::input::pressed);

                break;
            }
            case WM_LBUTTONUP:
            case WM_RBUTTONUP:
            case WM_MBUTTONUP:
            {
                const auto code = msg == WM_LBUTTONUP ? VK_LBUTTON :
                                  msg == WM_RBUTTONUP ? VK_RBUTTON : VK_MBUTTON;

                process_btn_message(hwnd, code, core::input::released);

                break;
            }
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
            {
                if ((lparam & 1 << 30) == 0)
                {
                    process_key_message(hwnd, wparam, core::input::pressed);
                }

                break;
            }
            case WM_KEYUP:
            case WM_SYSKEYUP:
            {
                process_key_message(hwnd, wparam, core::input::released);

                break;
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
        if (const auto window_input = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                       window_input && window_input->callbacks.btn_press)
        {
            if (const auto iterator  = window_input->codes.find(code);
                           iterator != window_input->codes.end())
            {
                window_input->callbacks.btn_press(iterator->second, state);
            }
        }
    }

    auto WindowEvents::process_key_message(const HWND hwnd, const uintptr_t code, const core::input::state state) -> void
    {
        if (const auto window_input = static_cast<WindowInput*>(GetProp(hwnd, "input"));
                       window_input && window_input->callbacks.key_press)
        {
            if (const auto iterator  = window_input->codes.find(code);
                           iterator != window_input->codes.end())
            {
                window_input->callbacks.key_press(iterator->second, state);
            }
        }
    }
}