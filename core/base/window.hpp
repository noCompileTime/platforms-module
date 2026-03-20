#pragma once

namespace core::base
{
    class Window
    {
    public:
                 Window() = default;
        virtual ~Window() = default;

        virtual auto  create(const window::settings& settings) noexcept -> void = 0;
        virtual auto destroy()                           const noexcept -> void = 0;

        virtual auto title(std::string_view title) const noexcept -> void = 0;
        virtual auto  show()                       const noexcept -> void = 0;

        [[nodiscard]] virtual auto handle() const noexcept -> std::any = 0; // TODO this as an operator or something?
    };
}