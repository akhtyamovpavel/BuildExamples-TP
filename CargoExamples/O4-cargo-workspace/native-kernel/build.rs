use std::env;
use std::path::PathBuf;
use std::process::Command;

fn main() {
    let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
    let obj = out_dir.join("kernel.o");
    let lib = out_dir.join("libkernel.a");
    assert!(Command::new("gcc")
        .args(["-O3", "-fPIC", "-c", "src/kernel.c", "-o"])
        .arg(&obj)
        .status()
        .unwrap()
        .success());
    assert!(Command::new("ar")
        .args(["crus"])
        .arg(&lib)
        .arg(&obj)
        .status()
        .unwrap()
        .success());
    println!("cargo:rustc-link-search=native={}", out_dir.display());
    println!("cargo:rustc-link-lib=static=kernel");
    println!("cargo:rerun-if-changed=src/kernel.c");
}
