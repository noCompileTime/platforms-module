#pragma once

namespace core
{
    class PlatformFunctions
    {
    public:
        static auto init(const std::unique_ptr<base::PlatformFactory>& factory) noexcept -> void;
    };
}