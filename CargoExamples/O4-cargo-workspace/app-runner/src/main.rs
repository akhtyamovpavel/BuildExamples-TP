use native_kernel::safe_dot_product;

fn main() {
    let u = [1.5, 2.5, 3.5, 4.5];
    let v = [2.0, 2.0, 2.0, 2.0];
    let res = safe_dot_product(&u, &v);
    println!("Workspace C-FFI dot_product={:.1}", res);
}
