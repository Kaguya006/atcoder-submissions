use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i32; n]
    }

    let mut ans = 0;

    for x in a {
        if (x - 10) > 0 {
            ans += x - 10;
        }
    }

    println!("{}", ans);
}
