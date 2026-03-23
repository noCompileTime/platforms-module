#pragma once

namespace core::base
{
    class PlatformFunctions
    {
    public:
                 PlatformFunctions() = default;
        virtual ~PlatformFunctions() = default;

        virtual auto init()                   noexcept -> void = 0;
        virtual auto init_context_functions() noexcept -> void = 0;
    };
}