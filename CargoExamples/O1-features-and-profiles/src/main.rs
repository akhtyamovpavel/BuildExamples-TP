pub fn compute_checksum(data: &[u8]) -> u64 {
    #[cfg(feature = "fast-hash")]
    {
        // FNV-1a 64-bit hash
        let mut hash: u64 = 0xcbf29ce484222325;
        for &b in data {
            hash ^= b as u64;
            hash = hash.wrapping_mul(0x100000001b3);
        }
        hash
    }
    #[cfg(not(feature = "fast-hash"))]
    {
        data.iter().map(|&b| b as u64).sum()
    }
}

fn main() {
    let payload = b"PromProg-1C-MIPT-Cargo";
    let h = compute_checksum(payload);
    #[cfg(feature = "extended-metrics")]
    println!("Mode=EXTENDED_METRICS len={} checksum=0x{:016x}", payload.len(), h);
    #[cfg(not(feature = "extended-metrics"))]
    println!("Mode=DEFAULT checksum=0x{:016x}", h);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn checksum_is_deterministic() {
        let a = compute_checksum(b"bazel-cargo");
        let b = compute_checksum(b"bazel-cargo");
        assert_eq!(a, b);
        assert_ne!(a, 0);
    }
}
