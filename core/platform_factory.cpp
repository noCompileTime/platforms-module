#include "platform_factory.hpp"

#include "windows/platform_factory.hpp"

namespace core
{
    auto PlatformFactory::create() -> std::unique_ptr<base::PlatformFactory>
    {
        return std::make_unique<windows::PlatformFactory>();
    }
}