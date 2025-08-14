#pragma once

namespace core::base
{
    class WindowEvents
    {
    public:
        virtual auto     init(const std::any& handle) -> void = 0;
        virtual auto  release(const std::any& handle) -> void = 0;
        virtual auto   update()                 const -> void = 0;

        virtual ~WindowEvents() = default;

        std::function<void()> on_close { };
    };
}