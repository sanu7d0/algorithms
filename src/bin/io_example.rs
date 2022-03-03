fn main() {}

// 4 5 6
// let (a, b, c) = parse_line!(i32, i32, i32);
macro_rules! parse_line {
    ($($t: ty), +) => ({
        let mut line = String::new();
        std::io::stdin().read_line(&mut line).unwrap();

        let mut iter = line.split_whitespace();
        ($(iter.next().unwrap().parse::<$t>().unwrap()), +)
    })
}

// 2
// 15
// 8
// -> [15, 8]
fn n_line_with_single_int_to_vector() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let N = buf.trim().parse::<i32>().unwrap();
    buf.clear();

    let mut v = Vec::new();

    for _ in 0..N {
        stdin.read_line(&mut buf).unwrap();
        v.push(buf.trim().parse::<i32>().unwrap());
        buf.clear();
    }
}

// 11 23 51
// -> [11, 23, 51]
fn multiple_int_with_whitespace_to_vector() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let v: Vec<i32> = buf
        .split_whitespace()
        .map(|c| c.trim().parse().unwrap())
        .collect();
}

// 54321
// -> [5, 4, 3, 2, 1]
fn serial_line_to_vector() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let v: Vec<i32> = buf.trim().chars().map(|c| c as i32 - '0' as i32).collect();
}

// hello world
// -> ["hello", "world"]
fn sentence_to_vector() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let v: Vec<String> = buf.split_whitespace().map(|s| s.to_string()).collect();
}

// hello
// -> ['h', 'e', 'l', 'l', 'o']
fn string_to_vector() {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let v: Vec<char> = buf.trim().chars().collect();
}

use std::fmt::Write;
fn output1() {
    let v = vec![4, 3, 2];
    let mut buf = String::new();

    for i in v {
        writeln!(&mut buf, "{}", i).unwrap();
    }
    print!("{}", buf);
}
