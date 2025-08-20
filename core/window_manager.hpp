#pragma once

#include "base/platforms_factory.hpp"

namespace core
{
    class WindowManager
    {
    public:
        auto    init()       -> void;
        auto release() const -> void;

        auto  window()        const -> base::Window&;
        auto  window_events() const -> base::WindowEvents&;
        auto  window_input()  const -> base::WindowInput&;

    private:
        std::unique_ptr<base::Window>       _window;
        std::unique_ptr<base::WindowEvents> _window_events;
        std::unique_ptr<base::WindowInput>  _window_input;
    };
}