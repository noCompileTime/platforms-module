#pragma once

namespace windows
{
    class WindowInput final : public core::base::WindowInput
    {
    public:
        auto    init(const core::base::window_ptr& window)       -> void override;
        auto release(const core::base::window_ptr& window) const -> void override;

    private:
        auto init_codes() -> void override;
    };
}