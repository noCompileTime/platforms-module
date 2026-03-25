#include "platform_functions.hpp"

namespace core
{
    auto PlatformFunctions::init(const std::unique_ptr<base::PlatformFactory>& factory) noexcept -> void
    {
        const auto window = factory->create_window();
                   window->create({ "base_window_context" });

        const auto context = factory->create_window_context();
                   context->create(*window);

        const auto functions = factory->create_platform_functions();
                   functions->init_context_functions();

        context->destroy();
         window->destroy();

         functions->init();
    }
}