
#include <Source/O3deFramework_InteractionSystemComponent.h>

#include <O3deFramework_InteractionTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace O3deFramework
{
    AZ_COMPONENT_IMPL(O3deFramework_InteractionSystemComponent, "O3deFramework_InteractionSystemComponent",
        O3deFramework_InteractionSystemComponentTypeId, BaseSystemComponent);

    void O3deFramework_InteractionSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3deFramework_InteractionSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void O3deFramework_InteractionSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("O3deFramework_InteractionService"));
    }

    void O3deFramework_InteractionSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("O3deFramework_InteractionService"));
    }

    void O3deFramework_InteractionSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void O3deFramework_InteractionSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    O3deFramework_InteractionSystemComponent::O3deFramework_InteractionSystemComponent() = default;
    O3deFramework_InteractionSystemComponent::~O3deFramework_InteractionSystemComponent() = default;

    void O3deFramework_InteractionSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();
    }

    void O3deFramework_InteractionSystemComponent::Deactivate()
    {
        BaseSystemComponent::Deactivate();
    }
}
