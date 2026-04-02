#pragma once

namespace core
{
    class PlatformFactory // TODO rename this to WindowFactory at some point
    {
    public:
        static auto create() noexcept -> std::unique_ptr<base::PlatformFactory>;
    };
}