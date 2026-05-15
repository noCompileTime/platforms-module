#pragma once

namespace windows
{
    class WindowContext final : public core::base::WindowContext
    {
    public:
        auto  create(const core::base::Window& window)                                         noexcept -> void override;
        auto  create(const core::base::Window& window, const core::window::settings& settings) noexcept -> void override;

        auto destroy()                 const noexcept -> void override;
        auto  update()                 const noexcept -> void override;
        auto   vsync(int32_t interval) const noexcept -> void override;

    private:
        HGLRC _hrc { };
        HDC   _hdc { };
    };
}