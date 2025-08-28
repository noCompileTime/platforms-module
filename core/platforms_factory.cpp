#include "platforms_factory.hpp"

#include "windows/platforms_factory.hpp"

namespace core
{
    auto PlatformsFactory::create_factory() -> std::unique_ptr<base::PlatformsFactory>
    {
        #ifdef WIN32
        return std::make_unique<windows::PlatformsFactory>();
        #endif
    }
}