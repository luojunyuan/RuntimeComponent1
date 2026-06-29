module;

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <SDKDDKVer.h>
#include <Windows.h>
#include <TraceLoggingProvider.h>

#pragma warning(push)
#pragma warning(disable: 6387 6553 26400 26401 26409 26439)
#include <wil/TraceLogging.h>
#pragma warning(pop)

export module ixx.MuxcTraceLogging;

import inc.win32;

export inline constexpr ULONGLONG KeywordItemsRepeater = 0x0000000000000001;
export inline constexpr ULONGLONG KeywordScrollPresenter = 0x0000000000000002;
export inline constexpr ULONGLONG KeywordPtr = 0x0000000000000004;
export inline constexpr ULONGLONG KeywordScrollView = 0x0000000000000008;
export inline constexpr ULONGLONG KeywordSwipeControl = 0x0000000000000010;
export inline constexpr ULONGLONG KeywordCommandBarFlyout = 0x0000000000000020;
export inline constexpr ULONGLONG KeywordWebView2 = 0x0000000000000040;
export inline constexpr ULONGLONG KeywordTabView = 0x0000000000000080;
export inline constexpr ULONGLONG KeywordItemsView = 0x0000000000000100;
export inline constexpr ULONGLONG KeywordItemContainer = 0x0000000000000200;
export inline constexpr ULONGLONG KeywordLinedFlowLayout = 0x0000000000000400;
export inline constexpr ULONGLONG KeywordAnnotatedScrollBar = 0x0000000000000800;
export inline constexpr ULONGLONG KeywordSelectorBar = 0x0000000000001000;
export inline constexpr ULONGLONG KeywordNavigationView = 0x0000000000002000;
export inline constexpr ULONGLONG KeywordInkToolbar = 0x0000000000004000;
export inline constexpr ULONGLONG KeywordTitleBar = 0x0000000000008000;

export inline constexpr PCSTR TelemetryProviderName = "Microsoft.UI.Xaml.Controls";
export inline constexpr PCSTR PerfProviderName = "Microsoft.UI.Xaml.Controls.Perf";
export inline constexpr PCSTR DebugProviderName = "Microsoft.UI.Xaml.Controls.Debug";

export
{
TRACELOGGING_DECLARE_PROVIDER(g_hTelemetryProvider);
extern bool g_IsTelemetryProviderEnabled;
extern UCHAR g_TelemetryProviderLevel;
extern ULONGLONG g_TelemetryProviderMatchAnyKeyword;
extern GUID g_TelemetryProviderActivityId;

TRACELOGGING_DECLARE_PROVIDER(g_hPerfProvider);
extern bool g_IsPerfProviderEnabled;
extern UCHAR g_PerfProviderLevel;
extern ULONGLONG g_PerfProviderMatchAnyKeyword;
extern GUID g_PerfProviderActivityId;

TRACELOGGING_DECLARE_PROVIDER(g_hLoggingProvider);
extern bool g_IsLoggingProviderEnabled;
extern UCHAR g_LoggingProviderLevel;
extern ULONGLONG g_LoggingProviderMatchAnyKeyword;
extern GUID g_LoggingProviderActivityId;

void RegisterTraceLogging();
void UnRegisterTraceLogging();

#pragma warning(push)
#pragma warning(disable: 6387)
DECLARE_TRACELOGGING_CLASS(XamlTelemetryLogging, "Microsoft-Windows-XAML", (0x531a35ab, 0x63ce, 0x4bcf, 0xaa, 0x98, 0xf8, 0x8c, 0x7a, 0x89, 0xe4, 0x55));

class XamlTelemetry final : public TelemetryBase
{
    IMPLEMENT_TELEMETRY_CLASS(XamlTelemetry, XamlTelemetryLogging);

public:
    DEFINE_TRACELOGGING_EVENT_PARAM4(PublicApiCall,
        bool, IsStart,
        std::uint64_t, ObjectPointer,
        PCSTR, MethodName,
        std::uint32_t, HR,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM4(PerfXamlEvent,
        bool, IsStart,
        std::uint64_t, ObjectPointer,
        PCSTR, EventName,
        bool, IsInteresting,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM2(WebView2_FireNavigationCompleted,
        std::uint64_t, ObjectPointer,
        bool, hasEventHandlers,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM2(WebView2_CreateCoreObjects,
        bool, IsStart,
        std::uint64_t, ObjectPointer,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM2(WebView2_TryCompleteInitialization,
        bool, IsStart,
        std::uint64_t, ObjectPointer,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM3(WebView2_DragStartingCallback_WithContentType_Failed,
        HRESULT, HR,
        std::uint32_t, ContentType,
        PCWSTR, ErrorMessage,
        TraceLoggingLevel(WINEVENT_LEVEL_ERROR));

    DEFINE_TRACELOGGING_EVENT_PARAM2(WebView2_DragStartingCallback_Failed,
        HRESULT, HR,
        PCWSTR, ErrorMessage,
        TraceLoggingLevel(WINEVENT_LEVEL_ERROR));

    DEFINE_TRACELOGGING_EVENT_PARAM2(MapControl_InitializeWebMap,
        bool, IsStart,
        std::uint64_t, ObjectPointer,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM1(MapControl_WebViewNavigationCompleted,
        std::uint64_t, ObjectPointer,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));

    DEFINE_TRACELOGGING_EVENT_PARAM2(MapControl_WebMessageReceived_Error,
        std::uint64_t, ObjectPointer,
        PCWSTR, Message,
        TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE));
};

struct PerfXamlEvent_RAII
{
public:
    PerfXamlEvent_RAII(std::uint64_t objectPointer, PCSTR eventName, bool isInteresting) :
        m_objectPointer(objectPointer),
        m_eventName(eventName),
        m_isInteresting(isInteresting)
    {
        XamlTelemetry::PerfXamlEvent(true, m_objectPointer, m_eventName, m_isInteresting);
    }

    ~PerfXamlEvent_RAII()
    {
        XamlTelemetry::PerfXamlEvent(false, m_objectPointer, m_eventName, m_isInteresting);
    }

    PerfXamlEvent_RAII(const PerfXamlEvent_RAII&) = delete;
    PerfXamlEvent_RAII(PerfXamlEvent_RAII&&) = delete;
    PerfXamlEvent_RAII& operator=(const PerfXamlEvent_RAII&) = delete;
    PerfXamlEvent_RAII& operator=(PerfXamlEvent_RAII&&) = delete;

private:
    std::uint64_t m_objectPointer;
    PCSTR m_eventName;
    bool m_isInteresting;
};

struct SimpleXamlStartStopEvent_RAII
{
public:
    SimpleXamlStartStopEvent_RAII(const SimpleXamlStartStopEvent_RAII&) = delete;
    SimpleXamlStartStopEvent_RAII(SimpleXamlStartStopEvent_RAII&&) = delete;
    SimpleXamlStartStopEvent_RAII& operator=(const SimpleXamlStartStopEvent_RAII&) = delete;
    SimpleXamlStartStopEvent_RAII& operator=(SimpleXamlStartStopEvent_RAII&&) = delete;

protected:
    SimpleXamlStartStopEvent_RAII(std::uint64_t objectPointer) :
        m_objectPointer(objectPointer)
    {
    }

    std::uint64_t m_objectPointer;
};
#pragma warning(pop)
}
