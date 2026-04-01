
#pragma once

namespace O3deFramework
{
    // System Component TypeIds
    inline constexpr const char* O3deFramework_InteractionSystemComponentBaseTypeId = "{06377A75-B19F-4F78-BBF8-B910AD196134}";
    inline constexpr const char* O3deFramework_InteractionSystemComponentTypeId = "{257288B1-9D49-4648-95FA-168F32F6583B}";
    inline constexpr const char* O3deFramework_InteractionEditorSystemComponentTypeId = "{E522A746-EF1F-4A24-BB95-75EAC3B81C20}";

    // Module derived classes TypeIds
    inline constexpr const char* O3deFramework_InteractionModuleInterfaceTypeId = "{B5A394BF-2415-4475-BC64-F5D3CBAEA14A}";
    inline constexpr const char* O3deFramework_InteractionModuleTypeId = "{385C2659-AC3A-4BF5-B325-2FC713E4C5BF}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* O3deFramework_InteractionEditorModuleTypeId = O3deFramework_InteractionModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* O3deFramework_InteractionRequestsTypeId = "{0B9ED821-F03E-4BDA-8AE4-83FA30FA5FF0}";
}
