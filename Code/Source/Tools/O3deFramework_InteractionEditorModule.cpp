
#include <Source/O3deFramework_InteractionModuleInterface.h>
#include <O3deFramework_InteractionTypeIds.h>
#include <Source/Tools/O3deFramework_InteractionEditorSystemComponent.h>

namespace O3deFramework
{
    class O3deFramework_InteractionEditorModule : public O3deFramework_InteractionModuleInterface
    {
    public:
        AZ_RTTI(O3deFramework_InteractionEditorModule, O3deFramework_InteractionEditorModuleTypeId, O3deFramework_InteractionModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deFramework_InteractionEditorModule, AZ::SystemAllocator);

        O3deFramework_InteractionEditorModule()
        {
            // Append editor-only items.
            m_descriptors.insert(m_descriptors.end(), {
                O3deFramework_InteractionEditorSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = O3deFramework_InteractionModuleInterface::GetRequiredSystemComponents();

            // Append editor-only items.
            list.insert(list.end(), {
                azrtti_typeid<O3deFramework_InteractionEditorSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), O3deFramework::O3deFramework_InteractionEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deFramework_Interaction_Editor, O3deFramework::O3deFramework_InteractionEditorModule)
#endif
