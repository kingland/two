#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <ecs/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef MUD_MODULES
#include <infra/Types.h>
#include <pool/Types.h>
#include <type/Types.h>
#endif


namespace mud
{
    // Exported types
    
    
    export_ template <> MUD_ECS_EXPORT Type& type<mud::Entity>();
    export_ template <> MUD_ECS_EXPORT Type& type<mud::Entt>();
    export_ template <> MUD_ECS_EXPORT Type& type<mud::OEntt>();
    export_ template <> MUD_ECS_EXPORT Type& type<mud::Complex>();
}
