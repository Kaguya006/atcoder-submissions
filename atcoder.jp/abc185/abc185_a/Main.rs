use proconio::input;

fn main() {
    input! {
        scores: [i32; 4],
    }

    let mut min = 100;
    for score in scores {
        if score < min {
            min = score;
        }
    }

    println!("{}", min);
}
