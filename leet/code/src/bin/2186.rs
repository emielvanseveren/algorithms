pub fn min_steps(s: String, t: String) -> i32 {
    let mut s_count = [0i32; 52];
    let mut t_count = [0i32; 52];

    for c in s.chars() {
        s_count[c as usize - 'a' as usize] += 1;
    }
    for c in t.chars() {
        t_count[c as usize - 'a' as usize] += 1;
    }

    let count = s_count
        .iter()
        .zip(t_count.iter())
        .fold(0, |acc, (s, t)| acc + (s - t).abs());

    count
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn min_steps_example_1() {
        assert_eq!(min_steps("leetcode".to_string(), "coats".to_string()), 7);
    }
    #[test]
    fn min_steps_example_2() {
        assert_eq!(min_steps("night".to_string(), "thing".to_string()), 0);
    }
}
