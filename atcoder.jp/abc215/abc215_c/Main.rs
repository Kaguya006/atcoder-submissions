#![allow(dead_code)]

use proconio::marker::Chars;
use proconio::{fastout, input};
use std::collections::BTreeSet;
use std::collections::HashSet;
const MOD: i64 = 1_000_000_007;

// a! mod m
fn mod_factorial(a: i64, m: i64) -> i64 {
    let mut res = 1;

    for i in 1..=a {
        res = res * i % m;
    }

    res
}

// a^b mod m
fn mod_pow(a: i64, b: i64, m: i64) -> i64 {
    if b == 0 {
        1
    } else if b % 2 == 0 {
        let d = mod_pow(a, b / 2, m);
        (d * d) % m
    } else {
        (a * mod_pow(a, b - 1, m)) % m
    }
}

// nCr mod m
fn mod_combination(mut n: i64, k: i64, m: i64) -> i64 {
    let mut a = 1;
    let mut b = 1;

    for i in 1..=k {
        a = a * n % m;
        b = b * i % m;
        n -= 1;
    }

    a * mod_pow(b, m - 2, m) % m
}

#[fastout]
fn main() {
    input! {
        s: Chars,
        k: usize,
    }

    let mut ans = BTreeSet::new();
    dfs(
        s.clone(),
        k.clone(),
        vec![].clone(),
        HashSet::new().clone(),
        &mut ans,
    );

    let mut i = 1;
    for t in ans {
        if i == k {
            let tt: String = t.into_iter().collect();
            println!("{}", tt);
            break;
        }

        i += 1;
    }
}

fn dfs(
    s: Vec<char>,
    k: usize,
    current: Vec<char>,
    seen: HashSet<usize>,
    ans: &mut BTreeSet<Vec<char>>,
) {
    if current.len() == s.len() {
        ans.insert(current);
    } else {
        for i in 0..s.len() {
            if seen.contains(&i) {
                continue;
            }

            let mut new_seen = seen.clone();
            let mut selected = vec![s[i]];
            let mut next = current.clone();

            next.append(&mut selected);
            new_seen.insert(i);

            dfs(s.clone(), k.clone(), next.clone(), new_seen.clone(), ans);
        }
    }
}
