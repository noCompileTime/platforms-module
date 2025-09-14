#pragma once

#include "core/base/window_input.hpp"

namespace windows
{
    class WindowInput final : public core::base::WindowInput
    {
    public:
        auto    init(const std::unique_ptr<core::base::Window>& window)       -> void override;
        auto release(const std::unique_ptr<core::base::Window>& window) const -> void override;

    private:
        auto init_codes() -> void override;
    };
}