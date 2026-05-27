#pragma once

namespace windows
{
    class WindowInput final : public core::base::WindowInput
    {
    public:
        auto    init(const core::base::Window& window)       noexcept -> void override;
        auto release(const core::base::Window& window) const noexcept -> void override;

    private:
        auto init_codes() noexcept -> void override;
    };
}