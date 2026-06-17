#pragma once

namespace core
{
    class PlatformFactory // TODO rename this to WindowFactory at some point
    {
    public:
        [[nodiscard]] static auto create() noexcept -> std::unique_ptr<base::PlatformFactory>;
    };
}