# IUXControlsTestApp

Minimal CoreIsland-based host for exercising `Islands.UI.Xaml.Controls` from C#.

This is intentionally not a direct copy of WinUI's `MUXControlsTestApp`:

- it uses WinUI 2 through the `Microsoft.UI.Xaml` NuGet package;
- it uses `CoreIsland` instead of WinUI 3 / Windows App SDK;
- it references the local `Islands.UI.Xaml.Controls` native output through
  `Islands.UI.Xaml.Controls.Projection`;
- it starts with a focused TitleBar page and is meant to grow with TestHooks,
  ScrollViewPresenter, and ScrollView.

Build:

```powershell
& "C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\MSBuild.exe" Tests\IUXControlsTestApp\IUXControlsTestApp.csproj /p:Configuration=Debug /p:Platform=x64 /m:1 /v:minimal /nr:false
```

The project is kept out of the main `.slnx` build for now because SDK-style C#
projects are mapped to `AnyCPU` by that solution flow, while the UWP XAML VC
runtime SDKs require an explicit architecture (`x64`, `x86`, or `ARM64`).
