use std::fmt::Write;

fn memorize_fibo(v0: &mut Vec<i32>, v1: &mut Vec<i32>) {
    v0[0] = 1;
    v1[1] = 1;
    for n in 2..=40 {
        v0[n] += v0[n - 1] + v0[n - 2];
        v1[n] += v1[n - 1] + v1[n - 2];
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let T = buf.trim().parse::<i32>().unwrap();
    buf.clear();

    let mut v0: Vec<i32> = vec![0; 41];
    let mut v1: Vec<i32> = vec![0; 41];
    memorize_fibo(&mut v0, &mut v1);

    let mut output = String::new();
    for _ in 0..T {
        stdin.read_line(&mut buf).unwrap();
        let N = buf.trim().parse::<usize>().unwrap();
        buf.clear();

        writeln!(&mut output, "{} {}", v0[N], v1[N]).unwrap();
    }

    print!("{}", output);
}
