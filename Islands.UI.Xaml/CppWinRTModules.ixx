module;

#include <cassert>

export module CppWinRTModules;

export import winrt_base;
export import winrt.Windows.Foundation;
export import winrt.Windows.Foundation.Numerics;
export import winrt.Windows.Graphics;
export import winrt.Windows.Devices.Input;
export import winrt.Windows.UI.Input;
export import winrt.Windows.UI.Xaml;
export import winrt.Windows.UI.Xaml.Controls;
export import winrt.Windows.UI.Xaml.Controls.Primitives;
export import winrt.Windows.UI.Xaml.Input;
export import winrt.Microsoft.UI.Xaml.Controls;
export import winrt.Microsoft.UI.Xaml.Controls.AnimatedVisuals;
export import winrt.Islands.UI.Xaml.Controls;

export namespace winrt::Islands::UI::Xaml::Controls
{
    namespace implementation {}
    namespace factory_implementation {}
}

export namespace winrt
{
    namespace implementation = ::winrt::Islands::UI::Xaml::Controls::implementation;
    namespace factory_implementation = ::winrt::Islands::UI::Xaml::Controls::factory_implementation;

    using namespace ::winrt::Windows::Devices::Input;
    using namespace ::winrt::Windows::Foundation;
    using namespace ::winrt::Windows::Foundation::Numerics;
    using namespace ::winrt::Windows::Graphics;
    using namespace ::winrt::Windows::UI::Input;
    using namespace ::winrt::Windows::UI::Xaml;
    using namespace ::winrt::Windows::UI::Xaml::Controls;
    using namespace ::winrt::Windows::UI::Xaml::Controls::Primitives;
    using namespace ::winrt::Windows::UI::Xaml::Input;
    using IconSource = ::winrt::Microsoft::UI::Xaml::Controls::IconSource;
    using TitleBar = ::winrt::Islands::UI::Xaml::Controls::TitleBar;
    using TitleBarAutomationPeer = ::winrt::Islands::UI::Xaml::Controls::TitleBarAutomationPeer;
    using TitleBarTemplateSettings = ::winrt::Islands::UI::Xaml::Controls::TitleBarTemplateSettings;
}

export inline void MUX_ASSERT(bool condition)
{
    assert(condition);
}
