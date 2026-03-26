#pragma once

namespace windows
{
    class WindowInput final : public core::base::WindowInput
    {
        auto init_codes() noexcept -> void override;

    public:
        auto    init(const core::base::Window& window)       noexcept -> void override;
        auto release(const core::base::Window& window) const noexcept -> void override;
    };

    static constexpr auto input_prop_key = "input_";
}