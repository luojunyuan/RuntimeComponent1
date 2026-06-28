module;

#include <inspectable.h>
#include <windows.ui.xaml.hosting.referencetracker.h>

#include "ErrorHandling.h"

#include <cassert>

#ifndef MUX_ASSERT
#define MUX_ASSERT(condition) assert(condition)
#endif

export module common;

import std;
export import winrt_base;
export import winrt.Windows.Foundation;
export import winrt.Windows.Foundation.Collections;
export import winrt.Windows.Foundation.Metadata;
export import winrt.Windows.ApplicationModel.Activation;
export import winrt.Windows.ApplicationModel.Contacts;
export import winrt.Windows.ApplicationModel.Core;
export import winrt.Windows.ApplicationModel.DataTransfer;
export import winrt.Windows.ApplicationModel.DataTransfer.DragDrop;
export import winrt.Windows.ApplicationModel.Resources;
export import winrt.Windows.ApplicationModel.Resources.Core;
export import winrt.Windows.Devices.Geolocation;
export import winrt.Windows.Globalization;
export import winrt.Windows.Globalization.NumberFormatting;
export import winrt.Windows.Graphics;
export import winrt.Windows.Graphics.Imaging;
export import winrt.Windows.Graphics.Display;
export import winrt.Windows.Graphics.Effects;
export import winrt.Windows.Storage;
export import winrt.Windows.Storage.Streams;
export import winrt.Windows.System;
export import winrt.Windows.System.Power;
export import winrt.Windows.System.Profile;
export import winrt.Windows.System.Threading;
export import winrt.Windows.System.UserProfile;
export import winrt.Windows.UI;
export import winrt.Windows.UI.Composition;
export import winrt.Windows.UI.Composition.Interactions;
export import winrt.Windows.UI.Core;
export import winrt.Windows.UI.Input;
export import winrt.Windows.UI.Input.Inking;
export import winrt.Windows.UI.Text;
export import winrt.Windows.UI.ViewManagement;
export import winrt.Windows.UI.Xaml;
export import winrt.Windows.UI.Xaml.Automation;
export import winrt.Windows.UI.Xaml.Automation.Peers;
export import winrt.Windows.UI.Xaml.Automation.Provider;
export import winrt.Windows.UI.Xaml.Controls;
export import winrt.Windows.UI.Xaml.Controls.Primitives;
export import winrt.Windows.UI.Xaml.Data;
export import winrt.Windows.UI.Xaml.Documents;
export import winrt.Windows.UI.Xaml.Hosting;
export import winrt.Windows.UI.Xaml.Input;
export import winrt.Windows.UI.Xaml.Interop;
export import winrt.Windows.UI.Xaml.Markup;
export import winrt.Windows.UI.Xaml.Media;
export import winrt.Windows.UI.Xaml.Media.Animation;
export import winrt.Windows.UI.Xaml.Media.Imaging;
export import winrt.Windows.UI.Xaml.Shapes;
export import winrt.Windows.Data.Json;
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

    using namespace ::winrt::Windows;
    using namespace ::winrt::Windows::ApplicationModel::Activation;
    using namespace ::winrt::Windows::ApplicationModel::Contacts;
    using namespace ::winrt::Windows::ApplicationModel::Core;
    using namespace ::winrt::Windows::ApplicationModel::DataTransfer;
    using namespace ::winrt::Windows::ApplicationModel::DataTransfer::DragDrop;
    using namespace ::winrt::Windows::ApplicationModel::Resources;
    using namespace ::winrt::Windows::ApplicationModel::Resources::Core;
    using namespace ::winrt::Windows::Devices::Input;
    using namespace ::winrt::Windows::Devices::Geolocation;
    using namespace ::winrt::Windows::Foundation;
    using namespace ::winrt::Windows::Foundation::Collections;
    using namespace ::winrt::Windows::Foundation::Metadata;
    using namespace ::winrt::Windows::Foundation::Numerics;
    using namespace ::winrt::Windows::Globalization;
    using namespace ::winrt::Windows::Globalization::NumberFormatting;
    using namespace ::winrt::Windows::Graphics;
    using namespace ::winrt::Windows::Graphics::Display;
    using namespace ::winrt::Windows::Graphics::Imaging;
    using namespace ::winrt::Windows::Graphics::Effects;
    using namespace ::winrt::Windows::Storage;
    using namespace ::winrt::Windows::Storage::Streams;
    using namespace ::winrt::Windows::System;
    using namespace ::winrt::Windows::System::Power;
    using namespace ::winrt::Windows::System::Profile;
    using namespace ::winrt::Windows::System::Threading;
    using namespace ::winrt::Windows::System::UserProfile;
    using namespace ::winrt::Windows::UI;
    using namespace ::winrt::Windows::UI::Composition;
    using namespace ::winrt::Windows::UI::Composition::Interactions;
    using namespace ::winrt::Windows::UI::Core;
    using namespace ::winrt::Windows::UI::Input;
    using namespace ::winrt::Windows::UI::Text;
    using namespace ::winrt::Windows::UI::ViewManagement;
    using namespace ::winrt::Windows::UI::Xaml;
    using namespace ::winrt::Windows::UI::Xaml::Automation;
    using namespace ::winrt::Windows::UI::Xaml::Automation::Peers;
    using namespace ::winrt::Windows::UI::Xaml::Automation::Provider;
    using namespace ::winrt::Windows::UI::Xaml::Controls;
    using namespace ::winrt::Windows::UI::Xaml::Controls::Primitives;
    using namespace ::winrt::Windows::UI::Xaml::Data;
    using namespace ::winrt::Windows::UI::Xaml::Documents;
    using namespace ::winrt::Windows::UI::Xaml::Hosting;
    using namespace ::winrt::Windows::UI::Xaml::Input;
    using namespace ::winrt::Windows::UI::Xaml::Interop;
    using namespace ::winrt::Windows::UI::Xaml::Markup;
    using namespace ::winrt::Windows::UI::Xaml::Media;
    using namespace ::winrt::Windows::UI::Xaml::Media::Animation;
    using namespace ::winrt::Windows::UI::Xaml::Media::Imaging;
    using namespace ::winrt::Windows::UI::Xaml::Shapes;
    using IconSource = ::winrt::Microsoft::UI::Xaml::Controls::IconSource;
    using AppWindowTitleBar = ::winrt::Islands::UI::Xaml::Controls::AppWindowTitleBar;
    using InputNonClientPointerSource = ::winrt::Islands::UI::Xaml::Controls::InputNonClientPointerSource;
    using NonClientRegionKind = ::winrt::Islands::UI::Xaml::Controls::NonClientRegionKind;
    using TitleBar = ::winrt::Islands::UI::Xaml::Controls::TitleBar;
    using TitleBarAutomationPeer = ::winrt::Islands::UI::Xaml::Controls::TitleBarAutomationPeer;
    using TitleBarTemplateSettings = ::winrt::Islands::UI::Xaml::Controls::TitleBarTemplateSettings;
    using TitleBarWindowAdapter = ::winrt::Islands::UI::Xaml::Controls::TitleBarWindowAdapter;
    using namespace ::winrt::Windows::Web;
}

export using std::wstring_view;
export using namespace std::literals;
export using ResourceIdType = const winrt::hstring&;

export
{
#include "CppWinRTHelpers.h"
#include "RuntimeClassHelpers.h"
#include "SharedHelpers.h"
#include "BoxHelpers.h"
#include "CastHelpers.h"
#include "event.h"
#include "AutoHandle.h"
#include "GlobalDependencyProperty.h"
#include "CollectionHelper.h"
#include "RoutedEventHelpers.h"
}
//#include "MUXControlsFactory.h"
