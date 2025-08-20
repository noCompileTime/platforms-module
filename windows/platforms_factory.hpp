#pragma once

#include "core/base/platforms_factory.hpp"

namespace windows
{
    class PlatformsFactory final : public core::base::PlatformsFactory
    {
    public:
        auto create_window()        -> std::unique_ptr<core::base::Window>       override;
        auto create_window_events() -> std::unique_ptr<core::base::WindowEvents> override;
        auto create_window_input () -> std::unique_ptr<core::base::WindowInput>  override;
    };
}