#include "platforms_factory.hpp"

#ifdef _WIN32
#include "windows/platforms_factory.hpp"
#endif

namespace core
{
    auto PlatformsFactory::create_factory() -> std::unique_ptr<base::PlatformsFactory>
    {
        #ifdef _WIN32
        return std::make_unique<windows::PlatformsFactory>();
        #endif
    }
}