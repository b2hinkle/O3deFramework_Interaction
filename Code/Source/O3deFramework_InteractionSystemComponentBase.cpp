
#include <Source/O3deFramework_InteractionSystemComponentBase.h>

#include <O3deFramework_InteractionTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <Source/AutoGen/AutoComponentTypes.h>

namespace O3deFramework
{
    AZ_COMPONENT_IMPL(O3deFramework_InteractionSystemComponentBase, "O3deFramework_InteractionSystemComponentBase",
        O3deFramework_InteractionSystemComponentBaseTypeId);

    void O3deFramework_InteractionSystemComponentBase::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3deFramework_InteractionSystemComponentBase, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void O3deFramework_InteractionSystemComponentBase::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("O3deFramework_InteractionBaseService"));
    }

    void O3deFramework_InteractionSystemComponentBase::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("O3deFramework_InteractionBaseService"));
    }

    void O3deFramework_InteractionSystemComponentBase::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void O3deFramework_InteractionSystemComponentBase::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    O3deFramework_InteractionSystemComponentBase::O3deFramework_InteractionSystemComponentBase()
    {
        if (O3deFramework_InteractionInterface::Get() == nullptr)
        {
            O3deFramework_InteractionInterface::Register(this);
        }
    }

    O3deFramework_InteractionSystemComponentBase::~O3deFramework_InteractionSystemComponentBase()
    {
        if (O3deFramework_InteractionInterface::Get() == this)
        {
            O3deFramework_InteractionInterface::Unregister(this);
        }
    }

    void O3deFramework_InteractionSystemComponentBase::Init()
    {
    }

    void O3deFramework_InteractionSystemComponentBase::Activate()
    {
        O3deFramework_InteractionRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();

        // Register our auto-components.
        RegisterMultiplayerComponents();
    }

    void O3deFramework_InteractionSystemComponentBase::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        O3deFramework_InteractionRequestBus::Handler::BusDisconnect();
    }

    void O3deFramework_InteractionSystemComponentBase::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }
}
