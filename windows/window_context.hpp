#pragma once

#include "core/base/window_context.hpp"

namespace windows
{
    class WindowContext final : public core::base::WindowContext
    {
    public:
        auto  create(const std::unique_ptr<core::base::Window>& window) -> void override;

        auto destroy()     const -> void override;
        auto  update()     const -> void override;

    private:
        HGLRC _hrc { };
        HDC   _hdc { };
    };
}