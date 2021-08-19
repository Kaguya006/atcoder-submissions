use proconio::input;

fn main() {
    input! { mut s: String }
    s = s.chars().rev().collect::<String>();

    for c in s.chars() {
        match c {
            '0' => print!("0"),
            '1' => print!("1"),
            '6' => print!("9"),
            '8' => print!("8"),
            '9' => print!("6"),
            _ => println!(""),
        }
    }
    println!("");
}
