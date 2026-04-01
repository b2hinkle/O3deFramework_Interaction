
#pragma once

#include <O3deFramework_InteractionTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace O3deFramework
{
    class O3deFramework_InteractionRequests
    {
    public:
        AZ_RTTI(O3deFramework_InteractionRequests, O3deFramework_InteractionRequestsTypeId);
        virtual ~O3deFramework_InteractionRequests() = default;
        // Put your public methods here
    };

    class O3deFramework_InteractionBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using O3deFramework_InteractionRequestBus = AZ::EBus<O3deFramework_InteractionRequests, O3deFramework_InteractionBusTraits>;
    using O3deFramework_InteractionInterface = AZ::Interface<O3deFramework_InteractionRequests>;

}
