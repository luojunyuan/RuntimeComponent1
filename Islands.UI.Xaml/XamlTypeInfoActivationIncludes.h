#pragma once

#include <cassert>
#include <functional>
#include <list>
#include <string_view>
#include <type_traits>
#include <utility>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#ifdef GetCurrentTime
#undef GetCurrentTime
#endif
#include <inspectable.h>
#include <windows.ui.xaml.hosting.referencetracker.h>

#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.Foundation.Numerics.h>
#include <winrt/Windows.Graphics.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.Xaml.Automation.Peers.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.AnimatedVisuals.h>
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>
#include <winrt/Islands.UI.Xaml.Controls.h>

#ifndef MUX_ASSERT
#define MUX_ASSERT(condition) assert(condition)
#endif

namespace winrt::Islands::UI::Xaml::Controls
{
    namespace implementation {}
    namespace factory_implementation {}
}

namespace winrt
{
    namespace implementation = ::winrt::Islands::UI::Xaml::Controls::implementation;
    namespace factory_implementation = ::winrt::Islands::UI::Xaml::Controls::factory_implementation;

    using namespace ::winrt::Windows::ApplicationModel::Core;
    using namespace ::winrt::Windows::Foundation;
    using namespace ::winrt::Windows::Foundation::Collections;
    using namespace ::winrt::Windows::Foundation::Metadata;
    using namespace ::winrt::Windows::Foundation::Numerics;
    using namespace ::winrt::Windows::Graphics;
    using namespace ::winrt::Windows::Storage::Streams;
    using namespace ::winrt::Windows::System;
    using namespace ::winrt::Windows::UI;
    using namespace ::winrt::Windows::UI::Composition;
    using namespace ::winrt::Windows::UI::Text;
    using namespace ::winrt::Windows::UI::Xaml;
    using namespace ::winrt::Windows::UI::Xaml::Automation;
    using namespace ::winrt::Windows::UI::Xaml::Automation::Peers;
    using namespace ::winrt::Windows::UI::Xaml::Controls;
    using namespace ::winrt::Windows::UI::Xaml::Controls::Primitives;
    using namespace ::winrt::Windows::UI::Xaml::Data;
    using namespace ::winrt::Windows::UI::Xaml::Input;
    using namespace ::winrt::Windows::UI::Xaml::Interop;
    using namespace ::winrt::Windows::UI::Xaml::Markup;
    using namespace ::winrt::Windows::UI::Xaml::Media;
    using namespace ::winrt::Windows::UI::Xaml::Media::Animation;
    using IconSource = ::winrt::Microsoft::UI::Xaml::Controls::IconSource;
    using TitleBar = ::winrt::Islands::UI::Xaml::Controls::TitleBar;
    using TitleBarAutomationPeer = ::winrt::Islands::UI::Xaml::Controls::TitleBarAutomationPeer;
    using TitleBarTemplateSettings = ::winrt::Islands::UI::Xaml::Controls::TitleBarTemplateSettings;
}

using std::wstring_view;
using namespace std::literals;
using ResourceIdType = const winrt::hstring&;

#include "CppWinRTHelpers.h"
#include "RuntimeClassHelpers.h"
#include "SharedHelpers.h"
#include "BoxHelpers.h"
#include "CastHelpers.h"
#include "event.h"
#include "GlobalDependencyProperty.h"
#include "CollectionHelper.h"
#include "RoutedEventHelpers.h"

#include "TitleBar.h"
#include "TitleBarTemplateSettings.h"
#include "TitleBarAutomationPeer.h"
