fn input() -> (i32, Vec<i32>) {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let N = buf.trim().parse::<i32>().unwrap();
    buf.clear();

    stdin.read_line(&mut buf).unwrap();
    let v: Vec<i32> = buf
        .split_whitespace()
        .map(|c| c.trim().parse().unwrap())
        .collect();
    (N, v)
}

fn main() {
    let (N, mut v) = input();
    v.sort_unstable();

    let mut sum: i32 = v[0];
    if (N > 1) {
        for i in 0usize..(N as usize - 1) {
            v[i + 1] += v[i];
            sum += v[i + 1];
        }
    }

    println!("{}", sum);
}
