#pragma once

#include "window_ptr.hpp"

namespace core::base
{
    class WindowInput
    {
    public:
        virtual ~WindowInput() = default;

        virtual auto    init(const window_ptr& window)       -> void = 0;
        virtual auto release(const window_ptr& window) const -> void = 0;

        window::input_callbacks callbacks;
        window::input_codes     codes;

    private:
        virtual auto init_codes() -> void = 0;
    };
}