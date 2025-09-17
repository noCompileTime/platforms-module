#pragma once

namespace windows
{
    class PlatformFunctions final : public core::base::PlatformFunctions
    {
    public:
        auto init_window_context_functions() -> void override;
    };
}