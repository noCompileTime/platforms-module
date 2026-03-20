#pragma once

namespace windows
{
    class Window final : public core::base::Window
    {
    public:
        auto  create(const core::window::configuration& configuration) noexcept -> void override;
        auto destroy()                                           const noexcept -> void override;

        auto title(std::string_view title) const noexcept -> void override;
        auto  show()                       const noexcept -> void override;

        [[nodiscard]] auto handle() const noexcept -> std::any override;

    private:
        auto   register_class()       noexcept -> void;
        auto unregister_class() const noexcept -> void;

        auto   register_style(const core::window::configuration& configuration) noexcept -> void;

        uint32_t _style { WS_CLIPSIBLINGS | WS_CLIPCHILDREN };
        uint32_t _extra { WS_EX_APPWINDOW };

        HWND _hwnd { };
        ATOM _id   { };
    };
}