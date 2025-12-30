#pragma once

namespace windows
{
    class WindowInput final : public core::base::WindowInput
    {
    public:
        auto    init(const std::unique_ptr<core::base::Window>& window)       noexcept -> void override;
        auto release(const std::unique_ptr<core::base::Window>& window) const noexcept -> void override;

    private:
        auto init_codes() noexcept -> void override;
    };
}