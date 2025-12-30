#pragma once

namespace windows
{
    class PlatformFunctions final : public core::base::PlatformFunctions
    {
    public:
        auto init()                          noexcept -> void override;
        auto init_window_context_functions() noexcept -> void override;
    };
}