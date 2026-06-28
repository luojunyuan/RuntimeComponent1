#pragma once

#include "TitleBarWindowAdapter.g.h"

class TitleBarWindowAdapter :
    public winrt::implementation::TitleBarWindowAdapterT<TitleBarWindowAdapter>
{
public:
    TitleBarWindowAdapter(winrt::TitleBar const& titleBar);
    ~TitleBarWindowAdapter();

    int64_t WindowHandle();
    void WindowHandle(int64_t value);
    winrt::AppWindowTitleBar WindowTitleBar();
    winrt::InputNonClientPointerSource NonClientPointerSource();

    void SetTitleBar(winrt::UIElement const& titleBar);
    void NotifyWindowActivated(bool active);
    void SetCaptionInsets(double left, double right);
    int32_t HitTest(int32_t screenX, int32_t screenY, int32_t xamlRootScreenX, int32_t xamlRootScreenY);
    bool ApplyTitleBarWindowRegion(int64_t titleBarWindowHandle, int32_t xamlRootScreenX, int32_t xamlRootScreenY);

private:
    void UnregisterTitleChanged();
    void OnTitleChanged();
    void SyncWindowTitle();
    void SyncNonClientRegions();
    void EnsureDefaultWindowTitle();
    void ApplyWindowTitle(winrt::hstring const& title);
    void ResetWindowTitle(winrt::hstring const& lastAppliedTitle);

    winrt::UIElement m_titleBarElement{ nullptr };
    winrt::TitleBar m_titleBar{ nullptr };
    winrt::AppWindowTitleBar m_windowTitleBar{ nullptr };
    winrt::InputNonClientPointerSource m_nonClientPointerSource{ nullptr };
    winrt::hstring m_defaultWindowTitle{};
    winrt::hstring m_lastObservedTitle{};
    winrt::hstring m_lastAppliedTitle{};
    int64_t m_windowHandle{};
    int64_t m_titleChangedToken{};
    bool m_hasDefaultWindowTitle{};
};

namespace winrt::Islands::UI::Xaml::Controls::implementation
{
    using TitleBarWindowAdapter = ::TitleBarWindowAdapter;
}

namespace winrt::Islands::UI::Xaml::Controls::factory_implementation
{
    struct TitleBarWindowAdapter : TitleBarWindowAdapterT<TitleBarWindowAdapter, implementation::TitleBarWindowAdapter>
    {
    };
}
