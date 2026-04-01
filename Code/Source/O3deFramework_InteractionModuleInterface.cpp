
#include <Source/O3deFramework_InteractionModuleInterface.h>

#include <AzCore/Memory/Memory.h>

#include <O3deFramework_InteractionTypeIds.h>

#include <Source/O3deFramework_InteractionSystemComponent.h>
#include <Source/AutoGen/AutoComponentTypes.h>

namespace O3deFramework
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(O3deFramework_InteractionModuleInterface, "O3deFramework_InteractionModuleInterface", O3deFramework_InteractionModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(O3deFramework_InteractionModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(O3deFramework_InteractionModuleInterface, AZ::SystemAllocator);

    O3deFramework_InteractionModuleInterface::O3deFramework_InteractionModuleInterface()
    {
        // Append all items used by both editor and non-editor targets.
        m_descriptors.insert(m_descriptors.end(), {
            O3deFramework_InteractionSystemComponent::CreateDescriptor(),
            }
        );

        // Create descriptors for our auto-components. Important: These are supposed to be the last descriptors added.
        CreateComponentDescriptors(m_descriptors);
    }

    AZ::ComponentTypeList O3deFramework_InteractionModuleInterface::GetRequiredSystemComponents() const
    {
        // Append all items used by both editor and non-editor targets.
        return AZ::ComponentTypeList{

        };
    }
}
