#pragma once

#define CppWinRTActivatableClassWithFactory(className, factory) \
    namespace factory_implementation { using className = factory; }; \
    namespace implementation { using className = ::className; };

#define CppWinRTActivatableClassWithBasicFactory(className) \
    struct className##Factory : public winrt::factory_implementation::className##T<className##Factory, ::className> {}; \
    CppWinRTActivatableClassWithFactory(className, className##Factory)

#define CppWinRTActivatableClassWithDPFactory(className) \
    struct className##Factory : public winrt::factory_implementation::className##T<className##Factory, ::className> \
    { \
        className##Factory() { EnsureProperties(); } \
        static void ClearProperties() { ::className::ClearProperties(); }\
        static void EnsureProperties() { ::className::EnsureProperties(); }\
    }; \
    CppWinRTActivatableClassWithFactory(className, className##Factory)
