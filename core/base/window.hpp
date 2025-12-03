#pragma once

namespace core::base
{
    class Window
    {
    public:
                 Window() = default;
        virtual ~Window() = default;

        virtual auto  create(const window::configuration& configuration) -> void = 0;
        virtual auto destroy()                                    const  -> void = 0;

        virtual auto  handle()                       const -> std::any = 0;

        virtual auto   title(std::string_view title) const ->     void = 0;
        virtual auto    show()                       const ->     void = 0;
    };
}