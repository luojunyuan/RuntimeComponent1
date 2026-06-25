module;
#pragma warning(disable: 4100) // unused parameter

#include <Windows.h>
#include <cassert>

export module CppWinRTModules;

import winrt.Windows.Foundation;
import winrt.Windows.Foundation.Collections;
import winrt.Windows.Foundation.Metadata;
import winrt.Windows.ApplicationModel.Activation;
import winrt.Windows.ApplicationModel.Contacts;
import winrt.Windows.ApplicationModel.Core;
import winrt.Windows.ApplicationModel.DataTransfer;
import winrt.Windows.ApplicationModel.DataTransfer.DragDrop;
import winrt.Windows.ApplicationModel.Resources;
import winrt.Windows.ApplicationModel.Resources.Core;
import winrt.Windows.Devices.Geolocation;
import winrt.Windows.Globalization;
import winrt.Windows.Globalization.NumberFormatting;
import winrt.Windows.Graphics;
import winrt.Windows.Graphics.Imaging;
import winrt.Windows.Graphics.Display;
import winrt.Windows.Graphics.Effects;
import winrt.Windows.Storage;
import winrt.Windows.Storage.Streams;
import winrt.Windows.System;
import winrt.Windows.System.Power;
import winrt.Windows.System.Profile;
import winrt.Windows.System.Threading;
import winrt.Windows.System.UserProfile;
import winrt.Windows.UI;
import winrt.Windows.UI.Composition;
import winrt.Windows.UI.Composition.Interactions;
import winrt.Windows.UI.Core;
import winrt.Windows.UI.Input;
import winrt.Windows.UI.Input.Inking;
import winrt.Windows.UI.Text;
import winrt.Windows.UI.ViewManagement;
import winrt.Windows.UI.Xaml;
import winrt.Windows.UI.Xaml.Automation;
import winrt.Windows.UI.Xaml.Automation.Peers;
import winrt.Windows.UI.Xaml.Automation.Provider;
import winrt.Windows.UI.Xaml.Controls;
import winrt.Windows.UI.Xaml.Controls.Primitives;
import winrt.Windows.UI.Xaml.Data;
import winrt.Windows.UI.Xaml.Documents;
import winrt.Windows.UI.Xaml.Hosting;
import winrt.Windows.UI.Xaml.Input;
import winrt.Windows.UI.Xaml.Interop;
import winrt.Windows.UI.Xaml.Markup;
import winrt.Windows.UI.Xaml.Media;
import winrt.Windows.UI.Xaml.Media.Animation;
import winrt.Windows.UI.Xaml.Media.Imaging;
import winrt.Windows.UI.Xaml.Shapes;
import winrt.Windows.Data.Json;

namespace winrt
{
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
    using namespace ::winrt::Windows::Web;
}

#ifndef MUX_ASSERT
#define MUX_ASSERT(condition) assert(condition)
#endif

#include "SharedHelpers.h"
