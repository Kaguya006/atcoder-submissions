use proconio::input;

fn main() {
    input! {
        n: i32,
        a: u32,
        b: u32,
    }

    let mut ans = 0;
    for i in 1..=n {
        let numbers = i.to_string();
        let sum: u32 = numbers.chars().map(|x| x.to_digit(10).unwrap()).sum();
        if sum <= b && sum >= a {
            ans += i;
        }
    }

    println!("{}", ans);
}
