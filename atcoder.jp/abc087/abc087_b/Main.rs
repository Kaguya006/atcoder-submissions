use proconio::input;

fn main() {
    input! {
        a: i32,
        b: i32,
        c: i32,
        x: i32,
    }

    let mut ans = 0;
    for n in 0..=a {
        for m in 0..=b {
            for l in 0..=c {
                let sum = 500 * n + 100 * m + 50 * l;
                if sum == x {
                    ans += 1;
                }
            }
        }
    }

    println!("{}", ans);
}
