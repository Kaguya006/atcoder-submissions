use proconio::input;

fn divisor(n : i64) -> Vec<i64> {
    let mut ret: Vec<i64> = Vec::new();
    let mut i = 1;
    while i * i <= n {
        if n % i == 0 {
            if i * i != n {
                ret.push(i);
                ret.push(n / i);
            } else {
                ret.push(i);
            }
        }
        i = i + 1;
    }
    return ret;
}

fn main() {
    input! {
        n: i64,
    }

    let mut ans = divisor(n);
    ans.sort();

    for x in ans {
        println!("{}", x);
    }
}
