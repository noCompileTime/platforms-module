#pragma once

namespace core::base
{
    class PlatformFunctions
    {
    public:
        virtual auto init_window_context_functions() -> void = 0;

        virtual ~PlatformFunctions() = default;
    };
}