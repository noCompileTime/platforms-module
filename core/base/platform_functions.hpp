#pragma once

namespace core::base
{
    class PlatformFunctions
    {
    public:
        virtual auto init()                          noexcept -> void = 0;
        virtual auto init_window_context_functions() noexcept -> void = 0;

        virtual ~PlatformFunctions() = default;
    };
}