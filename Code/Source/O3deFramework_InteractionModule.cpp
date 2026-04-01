
#include <Source/O3deFramework_InteractionModuleInterface.h>
#include <O3deFramework_InteractionTypeIds.h>
#include <Source/O3deFramework_InteractionSystemComponent.h>

namespace O3deFramework
{
    class O3deFramework_InteractionModule : public O3deFramework_InteractionModuleInterface
    {
    public:
        AZ_RTTI(O3deFramework_InteractionModule, O3deFramework_InteractionModuleTypeId, O3deFramework_InteractionModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deFramework_InteractionModule, AZ::SystemAllocator);

        O3deFramework_InteractionModule()
        {
            // Append non-editor items.
            m_descriptors.insert(m_descriptors.end(), {
                O3deFramework_InteractionSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = O3deFramework_InteractionModuleInterface::GetRequiredSystemComponents();

            // Append non-editor items.
            list.insert(list.end(), {
                azrtti_typeid<O3deFramework_InteractionSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), O3deFramework::O3deFramework_InteractionModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deFramework_Interaction, O3deFramework::O3deFramework_InteractionModule)
#endif
