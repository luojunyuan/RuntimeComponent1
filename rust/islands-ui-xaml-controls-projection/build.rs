use std::env;
use std::fs;
use std::path::{Path, PathBuf};

fn main() {
    let manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR"));
    let out_dir = PathBuf::from(env::var("OUT_DIR").expect("OUT_DIR"));
    let profile = env::var("PROFILE").expect("PROFILE");

    copy_runtime_assets(&manifest_dir, &out_dir, &profile);
}

fn copy_runtime_assets(manifest_dir: &Path, out_dir: &Path, profile: &str) {
    if env::var("CARGO_CFG_TARGET_OS").as_deref() != Ok("windows") {
        return;
    }

    let runtime_rid = match env::var("CARGO_CFG_TARGET_ARCH").as_deref() {
        Ok("x86_64") => "win-x64",
        Ok("x86") => "win-x86",
        Ok("aarch64") => "win-arm64",
        Ok(other) => {
            println!("cargo:warning=unsupported target arch for runtime asset copy: {other}");
            return;
        }
        Err(_) => return,
    };

    let runtime_dir = manifest_dir.join("runtimes").join(runtime_rid).join("native");
    println!("cargo:rerun-if-changed={}", runtime_dir.display());

    let target_dir = match find_profile_dir(out_dir, profile) {
        Some(path) => path,
        None => {
            println!("cargo:warning=failed to locate target output directory for runtime asset copy");
            return;
        }
    };

    for file_name in ["Islands.UI.Xaml.Controls.dll", "Islands.UI.Xaml.Controls.pri"] {
        let source = runtime_dir.join(file_name);
        if !source.is_file() {
            println!("cargo:warning=runtime asset not found: {}", source.display());
            continue;
        }

        let destination = target_dir.join(file_name);
        if let Some(parent) = destination.parent() {
            fs::create_dir_all(parent).expect("create runtime asset output directory");
        }

        fs::copy(&source, &destination).unwrap_or_else(|error| {
            panic!(
                "copy runtime asset {} -> {} failed: {error}",
                source.display(),
                destination.display()
            )
        });
    }
}

fn find_profile_dir(out_dir: &Path, profile: &str) -> Option<PathBuf> {
    out_dir
        .ancestors()
        .find(|path| path.file_name().and_then(|name| name.to_str()) == Some(profile))
        .map(Path::to_path_buf)
}
