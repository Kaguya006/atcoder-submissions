use proconio::input;

fn main() {
    input! {
         s: String,
    }
    let s: Vec<char> = s.chars().rev().collect();

    let mut s = &s[..];
    let patterns: Vec<Vec<char>> = ["dream", "dreamer", "erase", "eraser"]
        .iter()
        .map(|s| s.chars().rev().collect())
        .collect();
    let mut succeeded = true;
    while s.len() > 0 {
        let matched = patterns.iter().find(|&p| s.starts_with(p));
        if let Some(p) = matched {
            s = &s[p.len()..];
        } else {
            succeeded = false;
            break;
        }
    }

    println!("{}", if succeeded { "YES" } else { "NO" });
}
