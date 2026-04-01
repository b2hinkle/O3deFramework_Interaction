
#pragma once

#include <AzCore/Component/Component.h>
#include <O3deFramework_InteractionBus.h>
#include <AzCore/Component/TickBus.h>
#include <O3deFramework_InteractionConfiguration.h>

namespace O3deFramework
{
    class O3DEFRAMEWORK_INTERACTION_API O3deFramework_InteractionSystemComponentBase
        : public AZ::Component
        , protected O3deFramework_InteractionRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL_API(O3DEFRAMEWORK_INTERACTION_API, O3deFramework_InteractionSystemComponentBase);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        O3deFramework_InteractionSystemComponentBase();
        ~O3deFramework_InteractionSystemComponentBase();

    protected:
        //! O3deFramework_InteractionRequestBus::Handler overrides.
        //! @{
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        //! @}

        //! AZ::TickBus::Handler overrides.
        //! @{
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        //! @}
    };
}
