#![allow(dead_code)]

use proconio::{fastout, input};
const MOD: i64 = 1_000_000_007;

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

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
        s: [i64; n],
        t: [i64; n],
    }

    let min_number = *t.iter().min().unwrap();
    let min_idx = t.iter().position(|&r| r == min_number).unwrap();

    let mut time = vec![0; n];
    let mut previous_idx = 0;

    for i in min_idx..(min_idx + n) {
        let i = i % n;
        if i == min_idx {
            time[i] = t[i];
            previous_idx = i.clone();
        } else {
            let current_idx = i;
            if time[previous_idx] + s[previous_idx] < t[current_idx] {
                time[current_idx] = time[previous_idx] + s[previous_idx];
            } else {
                time[current_idx] = t[current_idx];
            }

            previous_idx = current_idx.clone();
        }
    }

    for x in time {
        println!("{}", x);
    }
}
