use proconio::input;
use std::collections::HashMap;

const MOD: i64 = 1000000007;

fn main() {
    input! { s: String }
    let mut mp = HashMap::<char, i64>::new();
    mp.insert('c', 0);
    mp.insert('h', 0);
    mp.insert('o', 0);
    mp.insert('k', 0);
    mp.insert('u', 0);
    mp.insert('d', 0);
    mp.insert('a', 0);
    mp.insert('i', 0);
    let mut ans = 0;

    for ch in s.chars() {
        match ch {
            'c' => *mp.get_mut(&'c').unwrap() = *mp.get_mut(&'c').unwrap() + 1 % MOD,
            'h' => *mp.get_mut(&'h').unwrap() += *mp.get_mut(&'c').unwrap() % MOD,
            'o' => *mp.get_mut(&'o').unwrap() += *mp.get_mut(&'h').unwrap() % MOD,
            'k' => *mp.get_mut(&'k').unwrap() += *mp.get_mut(&'o').unwrap() % MOD,
            'u' => *mp.get_mut(&'u').unwrap() += *mp.get_mut(&'k').unwrap() % MOD,
            'd' => *mp.get_mut(&'d').unwrap() += *mp.get_mut(&'u').unwrap() % MOD,
            'a' => *mp.get_mut(&'a').unwrap() += *mp.get_mut(&'d').unwrap() % MOD,
            'i' => ans += *mp.get_mut(&'a').unwrap() % MOD,
            _ => (),
        }
    }

    println!("{}", ans % MOD);
}
