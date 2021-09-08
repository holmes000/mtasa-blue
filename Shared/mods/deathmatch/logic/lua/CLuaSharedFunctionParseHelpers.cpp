/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto
 *               (Shared logic for modifications)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        shared/mods/deathmatch/logic/lua/CLuaSharedFunctionParseHelpers.cpp
 *  PURPOSE:
 *
 *****************************************************************************/

#include "StdInc.h"

IMPLEMENT_ENUM_CLASS_BEGIN(ePhysicsElementType)
ADD_ENUM(ePhysicsElementType::Unknown, "physics-unknown")
ADD_ENUM(ePhysicsElementType::WorldElement, "physics-world-element")
ADD_ENUM(ePhysicsElementType::RigidBody, "physics-rigidbody")
ADD_ENUM(ePhysicsElementType::StaticCollision, "physics-rigidbody")
ADD_ENUM(ePhysicsElementType::Shape, "physics-shape")
ADD_ENUM(ePhysicsElementType::ConvexShape, "physics-convex-shape")
ADD_ENUM(ePhysicsElementType::BoxShape, "physics-box-shape")
IMPLEMENT_ENUM_CLASS_END("physics-element-type")

SString GetSharedUserDataClassName(void* ptr, lua_State* luaVM)
{
    if (auto* pVar = UserDataCast<CLuaPhysicsRigidBody>((CLuaPhysicsRigidBody*)nullptr, ptr, luaVM))
        return GetClassTypeName(pVar);
    if (auto* pVar = UserDataCast<CLuaPhysicsStaticCollision>((CLuaPhysicsStaticCollision*)nullptr, ptr, luaVM))
        return GetClassTypeName(pVar);
    if (auto* pVar = UserDataCast<CLuaPhysicsShape>((CLuaPhysicsShape*)nullptr, ptr, luaVM))
        return GetClassTypeName(pVar);
    if (auto* pVar = UserDataCast<CLuaPhysicsElement>((CLuaPhysicsElement*)nullptr, ptr, luaVM))
        return GetClassTypeName(pVar);

    return "";
}
