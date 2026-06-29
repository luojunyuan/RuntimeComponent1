// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

module inc.common;

winrt::IconElement SharedHelpers::MakeIconElementFrom(winrt::IconSource const& iconSource)
{
    if (!iconSource)
    {
        return nullptr;
    }

    if (auto fontIconSource = iconSource.try_as<winrt::Microsoft::UI::Xaml::Controls::FontIconSource>())
    {
        auto icon = winrt::FontIcon();
        icon.Glyph(fontIconSource.Glyph());
        icon.FontSize(fontIconSource.FontSize());
        icon.FontWeight(fontIconSource.FontWeight());
        icon.FontStyle(fontIconSource.FontStyle());
        icon.IsTextScaleFactorEnabled(fontIconSource.IsTextScaleFactorEnabled());
        icon.MirroredWhenRightToLeft(fontIconSource.MirroredWhenRightToLeft());

        if (fontIconSource.FontFamily())
        {
            icon.FontFamily(fontIconSource.FontFamily());
        }
        if (fontIconSource.Foreground())
        {
            icon.Foreground(fontIconSource.Foreground());
        }

        return icon;
    }

    if (auto symbolIconSource = iconSource.try_as<winrt::Microsoft::UI::Xaml::Controls::SymbolIconSource>())
    {
        auto icon = winrt::SymbolIcon();
        icon.Symbol(static_cast<winrt::Symbol>(static_cast<int32_t>(symbolIconSource.Symbol())));
        if (symbolIconSource.Foreground())
        {
            icon.Foreground(symbolIconSource.Foreground());
        }
        return icon;
    }

    if (auto bitmapIconSource = iconSource.try_as<winrt::Microsoft::UI::Xaml::Controls::BitmapIconSource>())
    {
        auto icon = winrt::BitmapIcon();
        if (bitmapIconSource.UriSource())
        {
            icon.UriSource(bitmapIconSource.UriSource());
        }
        icon.ShowAsMonochrome(bitmapIconSource.ShowAsMonochrome());
        if (bitmapIconSource.Foreground())
        {
            icon.Foreground(bitmapIconSource.Foreground());
        }
        return icon;
    }

    if (auto pathIconSource = iconSource.try_as<winrt::Microsoft::UI::Xaml::Controls::PathIconSource>())
    {
        auto icon = winrt::PathIcon();
        if (pathIconSource.Data())
        {
            icon.Data(pathIconSource.Data());
        }
        if (pathIconSource.Foreground())
        {
            icon.Foreground(pathIconSource.Foreground());
        }
        return icon;
    }

    return nullptr;
}
