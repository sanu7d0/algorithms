use std::fmt::Write;

fn input(v: &mut Vec<i32>) {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let N = buf.trim().parse::<i32>().unwrap();

    buf.clear();
    for _ in 0..N {
        stdin.read_line(&mut buf).unwrap();
        v.push(buf.trim().parse::<i32>().unwrap());
        buf.clear();
    }
}

fn quick_sort(v: &mut Vec<i32>, start: usize, end: usize) {
    if start >= end {
        return;
    }
    let pivot = partition(&mut v, start, end);

    quick_sort(&mut v, start, (pivot - 1) as usize);
    quick_sort(&mut v, (pivot + 1) as usize, end);
}

fn partition(v: &mut Vec<i32>, start: usize, end: usize) -> i32 {
    let mut pivot = v[end];
    let mut index = start;

    let mut i = start;
    while i < end {
        if v[i] < pivot {
            swap(&mut v, i, index);
            index += 1;
        }

        i += 1;
    }
    swap(&mut v, index, end);

    return index as i32;
}

fn swap(v: &mut Vec<i32>, i: usize, j: usize) {
    let temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

fn output(v: &Vec<i32>) {
    let mut buf = String::new();
    for i in v {
        writeln!(&mut buf, "{}", i).unwrap();
    }
    print!("{}", buf);
}

fn main() {
    let mut v = Vec::new();
    input(&mut v);
    quick_sort(&mut v);
    output(&v);
}
