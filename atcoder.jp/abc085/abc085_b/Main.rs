use proconio::input;
use std::collections::BTreeSet;

fn main() {
    input! {
        n: usize,
        mut a: [u32; n],
    }

    let bt: BTreeSet<&u32> = a.iter().collect();
    println!("{}", bt.len());
}
