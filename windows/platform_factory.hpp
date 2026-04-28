#pragma once

namespace windows
{
    class PlatformFactory final : public core::base::PlatformFactory
    {
    public:
        [[nodiscard]] auto create_window()             const noexcept -> std::unique_ptr<core::base::Window>            override;
        [[nodiscard]] auto create_window_context()     const noexcept -> std::unique_ptr<core::base::WindowContext>     override;
        [[nodiscard]] auto create_window_events()      const noexcept -> std::unique_ptr<core::base::WindowEvents>      override;
        [[nodiscard]] auto create_window_input()       const noexcept -> std::unique_ptr<core::base::WindowInput>       override;

        [[nodiscard]] auto create_platform_functions() const noexcept -> std::unique_ptr<core::base::PlatformFunctions> override;
        [[nodiscard]] auto create_platform_monitor()   const noexcept -> std::unique_ptr<core::base::PlatformMonitor>   override;
    };
}