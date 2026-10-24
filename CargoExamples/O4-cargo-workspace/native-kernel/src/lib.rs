unsafe extern "C" {
    fn c_dot_product(a: *const f64, b: *const f64, n: usize) -> f64;
}

pub fn safe_dot_product(a: &[f64], b: &[f64]) -> f64 {
    assert_eq!(a.len(), b.len(), "Slices must have equal length");
    unsafe { c_dot_product(a.as_ptr(), b.as_ptr(), a.len()) }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_dot() {
        let a = [1.0, 2.0, 3.0];
        let b = [4.0, 5.0, 6.0];
        assert_eq!(safe_dot_product(&a, &b), 32.0);
    }
}
