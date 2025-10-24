#pragma once

namespace core
{
    class PlatformFactory
    {
    public:
        static auto create() -> std::unique_ptr<base::PlatformFactory>;
    };
}