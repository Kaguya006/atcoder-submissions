use proconio::input;
use std::collections::HashMap;

fn main() {
    input! {
        n: usize,
        a: [i32; n],
    }

    let mut counter: HashMap<i32, i64> = std::collections::HashMap::new();
    let mut ans: i64 = 0;
    for i in 0..n {
        ans += i as i64;
        match counter.get(&a[i]) {
            Some(v) => {
                ans -= *v;
            }
            None => (),
        }
        *counter.entry(a[i]).or_insert(0) += 1;
    }

    println!("{}", ans);
}
