#pragma once

namespace windows
{
    class PlatformFactory final : public core::base::PlatformFactory
    {
    public:
        auto create_platform_functions() const -> std::unique_ptr<core::base::PlatformFunctions> override;

        auto create_window()             const -> std::unique_ptr<core::base::Window>            override;
        auto create_window_context()     const -> std::unique_ptr<core::base::WindowContext>     override;
        auto create_window_events ()     const -> std::unique_ptr<core::base::WindowEvents>      override;
        auto create_window_input  ()     const -> std::unique_ptr<core::base::WindowInput>       override;
    };
}