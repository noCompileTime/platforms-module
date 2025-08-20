#pragma once

#include "window.hpp"
#include "window_input_callbacks.hpp"
#include "window_input_codes.hpp"

namespace core::base
{
    class WindowInput
    {
    public:
        virtual auto    init(const std::unique_ptr<Window>& window) -> void = 0;
        virtual auto release(const std::unique_ptr<Window>& window) -> void = 0;

        virtual ~WindowInput() = default;

        window_input_callbacks callbacks;
        window_input_codes     codes;

    private:
        virtual auto init_codes() -> void = 0;
    };
}