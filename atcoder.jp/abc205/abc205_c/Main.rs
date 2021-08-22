use proconio::input;

fn main() {
    input! {
        a: i32,
        b: i32,
        c: i32,
    }

    if c % 2 == 0 {
        if a.abs() < b.abs() {
            println!("<");
        } else if a.abs() > b.abs() {
            println!(">");
        } else {
            println!("=");
        };
    } else {
        if a < b {
            println!("<");
        } else if a > b {
            println!(">");
        } else {
            println!("=");
        };
    }
}
