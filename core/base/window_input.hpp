#pragma once

#include "window.hpp"

namespace core::base
{
    class WindowInput
    {
    public:
        virtual auto    init(const std::unique_ptr<Window>& window)       -> void = 0;
        virtual auto release(const std::unique_ptr<Window>& window) const -> void = 0;

        virtual ~WindowInput() = default;

        window::input_callbacks callbacks;
        window::input_codes     codes;

    private:
        virtual auto init_codes() -> void = 0;
    };
}