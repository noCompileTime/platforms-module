#pragma once

namespace windows
{
    class PlatformMonitor final : public core::base::PlatformMonitor
    {
    public:
        auto init() -> void override;
    };
}