#![allow(dead_code)]

use proconio::marker::*;
use proconio::{fastout, input};
use std::collections::*;
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
        n: i64,
    }

    let mut x = n;
    let mut ans = vec![];
    while x != 0 {
        if x % 2 == 0 {
            x /= 2;
            ans.push('B');
        } else {
            x -= 1;
            ans.push('A');
        }
    }

    let ans: String = ans.into_iter().rev().collect();
    println!("{}", ans);
}
