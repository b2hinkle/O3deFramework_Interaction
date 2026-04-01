
#include <Source/Tools/O3deFramework_InteractionEditorSystemComponent.h>

#include <O3deFramework_InteractionTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace O3deFramework
{
    AZ_COMPONENT_IMPL(O3deFramework_InteractionEditorSystemComponent, "O3deFramework_InteractionEditorSystemComponent",
        O3deFramework_InteractionEditorSystemComponentTypeId, BaseSystemComponent);

    void O3deFramework_InteractionEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3deFramework_InteractionEditorSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void O3deFramework_InteractionEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("O3deFramework_InteractionEditorService"));
    }

    void O3deFramework_InteractionEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("O3deFramework_InteractionEditorService"));
    }

    void O3deFramework_InteractionEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void O3deFramework_InteractionEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    O3deFramework_InteractionEditorSystemComponent::O3deFramework_InteractionEditorSystemComponent() = default;
    O3deFramework_InteractionEditorSystemComponent::~O3deFramework_InteractionEditorSystemComponent() = default;

    void O3deFramework_InteractionEditorSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();

        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void O3deFramework_InteractionEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();

        BaseSystemComponent::Deactivate();
    }
}
