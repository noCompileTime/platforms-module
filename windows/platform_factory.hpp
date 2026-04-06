#pragma once

namespace windows
{
    class PlatformFactory final : public core::base::PlatformFactory
    {
    public:
        auto create_window()             const noexcept -> std::unique_ptr<core::base::Window>            override; // TODO nodiscard on these?
        auto create_window_context()     const noexcept -> std::unique_ptr<core::base::WindowContext>     override;
        auto create_window_events()      const noexcept -> std::unique_ptr<core::base::WindowEvents>      override;
        auto create_window_input()       const noexcept -> std::unique_ptr<core::base::WindowInput>       override;

        auto create_platform_functions() const noexcept -> std::unique_ptr<core::base::PlatformFunctions> override;
        auto create_platform_monitor()   const noexcept -> std::unique_ptr<core::base::PlatformMonitor>   override;
    };
}