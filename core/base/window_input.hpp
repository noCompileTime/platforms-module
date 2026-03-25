#pragma once

namespace core::base
{
    class WindowInput
    {
    public:
                 WindowInput() = default;
        virtual ~WindowInput() = default;

        virtual auto    init(const Window& window)       noexcept -> void = 0;
        virtual auto release(const Window& window) const noexcept -> void = 0;

        window::input_callbacks callbacks;
        window::input_codes     codes; // TODO this should be private somehow

    private:
        virtual auto init_codes() noexcept -> void = 0;
    };
}