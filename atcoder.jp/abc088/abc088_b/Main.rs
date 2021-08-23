use proconio::input;

fn main() {
    input! {
        n: usize,
        mut a: [i32; n],
    }

    a.sort_by(|a, b| b.cmp(a));

    let mut alice = 0;
    let mut bob = 0;
    let mut i = 0;
    for x in a {
        if i % 2 == 0 {
            alice += x;
        } else {
            bob += x;
        }
        i += 1;
    }

    println!("{}", alice - bob);
}
