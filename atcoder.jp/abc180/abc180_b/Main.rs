use proconio::input;

fn main() {
    input! {
        n: usize,
        points: [i64; n],
    }

    let manhattan: i64 = points.iter().fold(0, |sum, p| sum + p.abs());
    let mut euclid: f64 = points.iter().fold(0, |sum, p| sum + p.abs().pow(2)) as f64;
    euclid = euclid.sqrt();
    let mut chebyshev: i64 = -1;
    for p in points {
        if chebyshev < p.abs() {
            chebyshev = p.abs();
        }
    }

    println!("{} {} {}", manhattan, euclid, chebyshev);
}
