module;

#include <cassert>

export module CppWinRTModules;

export import std;
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

export namespace winrt
{
    using namespace ::winrt::Windows::Devices::Input;
    using namespace ::winrt::Windows::Foundation;
    using namespace ::winrt::Windows::Foundation::Numerics;
    using namespace ::winrt::Windows::Graphics;
    using namespace ::winrt::Windows::UI::Input;
    using namespace ::winrt::Windows::UI::Xaml;
    using namespace ::winrt::Windows::UI::Xaml::Controls;
    using namespace ::winrt::Windows::UI::Xaml::Controls::Primitives;
    using namespace ::winrt::Windows::UI::Xaml::Input;
}

#pragma warning(disable: 4100) // unused parameter

export inline void MUX_ASSERT(bool condition)
{
    assert(condition);
}
