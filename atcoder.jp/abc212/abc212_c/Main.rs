#![allow(dead_code)]

use proconio::{fastout, input};
use std::cmp::min;

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
        n: usize,
        m: usize,
        mut a: [i32; n],
        mut b: [i32; m],
    }

    let mut tuple_list = vec![];

    for x in a {
        tuple_list.push((x, "a"));
    }

    for x in b {
        tuple_list.push((x, "b"));
    }

    tuple_list.sort_by_key(|k| k.0);

    let mut previous_flg = "";
    let mut previous_num = 0;
    let mut ans = 1000000000;
    for (num, flg) in tuple_list {
        if previous_flg != "" && previous_flg != flg {
            ans = min(ans, (previous_num - num).abs());
        }

        previous_num = num;
        previous_flg = flg;
    }

    println!("{}", ans);
}
