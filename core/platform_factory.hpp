#pragma once

namespace core
{
    class PlatformFactory
    {
    public:
        static auto create() noexcept -> std::unique_ptr<base::PlatformFactory>;
    };
}