# islands-ui-xaml-controls-projection

Rust projection crate for `Islands.UI.Xaml.Controls`.

The Rust bindings are pre-generated in `src/bindings_muxc.rs`. Consumers do not run `windows-bindgen`; they only depend on this crate and receive the same projection source every build.

## Use From Another Rust Project

Add the crate from this repository branch:

```toml
[dependencies]
islands-ui-xaml-controls-projection = { git = "https://github.com/luojunyuan/RuntimeComponent1", branch = "ixx-trans", package = "islands-ui-xaml-controls-projection" }
```

Use the projected APIs from the generated namespace:

```rust
use islands_ui_xaml_controls_projection::Islands::UI::Xaml::Controls::TitleBar;

fn create_title_bar() -> windows_core::Result<TitleBar> {
    TitleBar::new()
}
```

## Runtime Assets

The projection is only the Rust API surface. The native WinRT component still has to be available at runtime.

Place the built runtime files in this crate:

```text
runtimes/
  win-x86/native/
    Islands.UI.Xaml.Controls.dll
    Islands.UI.Xaml.Controls.pri
  win-x64/native/
    Islands.UI.Xaml.Controls.dll
    Islands.UI.Xaml.Controls.pri
  win-arm64/native/
    Islands.UI.Xaml.Controls.dll
    Islands.UI.Xaml.Controls.pri
```

On Windows targets, `build.rs` copies the matching `dll` and `pri` into the Cargo profile output directory, for example `target/debug` or `target/release`. Cargo does not handle `pri` files by itself, so this copy step is required.

## Regenerating Bindings

`src/bindings_muxc.rs` should be regenerated whenever `Islands.UI.Xaml.Controls.winmd` changes.

Use the same metadata inputs that produced the current projection:

```text
winmd/
  Islands.UI.Xaml.Controls.winmd
  Microsoft.UI.Xaml.winmd
```

The crate keeps `winmd/` as source material for maintainers. Normal consumers do not need it during build because `src/bindings_muxc.rs` is already checked in.
