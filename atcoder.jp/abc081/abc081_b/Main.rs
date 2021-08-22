use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [u32; n],
    }

    println!("{}", a.iter().map(|x| x.trailing_zeros()).min().unwrap());
}
