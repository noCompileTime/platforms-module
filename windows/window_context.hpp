#pragma once

namespace windows
{
    class WindowContext final : public core::base::WindowContext
    {
    public:
        auto  create(const std::unique_ptr<core::base::Window>& window)                                                   noexcept -> void override;
        auto  create(const std::unique_ptr<core::base::Window>& window, const core::window::configuration& configuration) noexcept -> void override;

        auto destroy()                 const noexcept -> void override;
        auto  update()                 const noexcept -> void override;
        auto    sync(int32_t interval) const noexcept -> void override;

    private:
        HGLRC _hrc { };
        HDC   _hdc { };
    };
}