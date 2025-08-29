#pragma once

#include "window.hpp"

namespace core::base
{
    class WindowInput
    {
    public:
        virtual auto    init(const std::unique_ptr<Window>& window) -> void = 0;
        virtual auto release(const std::unique_ptr<Window>& window) -> void = 0;

        virtual ~WindowInput() = default;

    private:
        virtual auto init_codes() -> void = 0;

    public:
        window::input_callbacks callbacks;
        window::input_codes     codes;
    };
}