#include "platform_functions.hpp"

namespace core
{
    auto PlatformFunctions::init(const std::unique_ptr<base::PlatformFactory>& factory) -> void
    {
        const auto window = factory->create_window();
                   window->create({ "base_window_context" });

        const auto window_context = factory->create_window_context();
                   window_context->create(window);

        const auto platform_functions = factory->create_platform_functions();
                   platform_functions->init_window_context_functions();

        window_context->destroy();
        window        ->destroy();

       platform_functions->init();
    }
}