use proconio::input;

fn main() {
    input! {
        n: usize,
        k: i32,
        mut p: [i32; n],
    }

    p.sort();
    let sum: i32 = p[0..k as usize].iter().sum();
    println!("{}", sum);
}
