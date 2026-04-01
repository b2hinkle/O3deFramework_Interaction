
#pragma once

#include <AzCore/PlatformDef.h>

#if defined(AZ_MONOLITHIC_BUILD)
#   define O3DEFRAMEWORK_INTERACTION_API
#else
#   if defined(O3DEFRAMEWORK_INTERACTION_EXPORTS)
#       define O3DEFRAMEWORK_INTERACTION_API AZ_DLL_EXPORT
#   else
#       define O3DEFRAMEWORK_INTERACTION_API AZ_DLL_IMPORT
#   endif
#endif
