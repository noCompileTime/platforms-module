#pragma once

#include "base/platforms_factory.hpp"

namespace core
{
    class PlatformsFactory
    {
    public:
        static auto create_factory() -> std::unique_ptr<base::PlatformsFactory>;
    };
}