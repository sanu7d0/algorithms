fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();

    let mut minus_flag: i32 = 1;
    let mut begin: usize = 0;
    let mut sum: i32 = 0;
    for (i, ch) in s.chars().enumerate() {
        if ch == '-' || ch == '+' || i == s.len() - 1 {
            let num = if i == s.len() - 1 {
                &s[begin..i + 1]
            } else {
                &s[begin..i]
            };

            sum += num.parse::<i32>().unwrap() * minus_flag;
            begin = i + 1;

            if ch == '-' {
                minus_flag = -1;
            }
        }
    }
    println!("{}", sum);

    let mut ans: Vec<i32> = Vec::new();
}
