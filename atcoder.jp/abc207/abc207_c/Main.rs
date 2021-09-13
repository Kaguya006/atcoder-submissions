use proconio::input;

fn main() {
    input! {
        n: usize,
        tlr: [[f64; 3]; n],
    }

    let mut ans = 0;
    for i in 0..n {
        for j in (i + 1)..n {
            let mut a = 0.0;
            let mut b = 0.0;
            let mut c = 0.0;
            let mut d = 0.0;

            match tlr[i][0] as i32 {
                1 => {
                    a = tlr[i][1];
                    b = tlr[i][2];
                }
                2 => {
                    a = tlr[i][1];
                    b = tlr[i][2] - 0.1;
                }
                3 => {
                    a = tlr[i][1] + 0.1;
                    b = tlr[i][2];
                }
                4 => {
                    a = tlr[i][1] + 0.1;
                    b = tlr[i][2] - 0.1;
                }
                _ => (),
            }

            match tlr[j][0] as i32 {
                1 => {
                    c = tlr[j][1];
                    d = tlr[j][2];
                }
                2 => {
                    c = tlr[j][1];
                    d = tlr[j][2] - 0.1;
                }
                3 => {
                    c = tlr[j][1] + 0.1;
                    d = tlr[j][2];
                }
                4 => {
                    c = tlr[j][1] + 0.1;
                    d = tlr[j][2] - 0.1;
                }
                _ => (),
            }

            if a > b || c > d {
                continue;
            }

            if (c <= a && a <= d) || (c <= b && b <= d) || (a <= c && c <= b) || (a <= d && d <= b)
            {
                ans += 1;
            }
        }
    }

    println!("{}", ans);
}
