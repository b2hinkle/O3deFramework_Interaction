
#pragma once

#include <AzCore/Module/Module.h>
#include <AzCore/Memory/Memory_fwd.h>
#include <AzCore/RTTI/RTTIMacros.h>
#include <AzCore/RTTI/TypeInfoSimple.h>
#include <O3deFramework_InteractionConfiguration.h>

namespace O3deFramework
{
    class O3DEFRAMEWORK_INTERACTION_API O3deFramework_InteractionModuleInterface : public AZ::Module
    {
    public:
        AZ_TYPE_INFO_WITH_NAME_DECL_API(O3DEFRAMEWORK_INTERACTION_API, O3deFramework_InteractionModuleInterface);
        AZ_RTTI_NO_TYPE_INFO_DECL();
        AZ_CLASS_ALLOCATOR_DECL;

        O3deFramework_InteractionModuleInterface();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}
