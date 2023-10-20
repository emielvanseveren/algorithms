// for short words we allocate 52 bytes.
// We could potentially have less memory usage if we use a hashmap
pub fn min_steps(s: String, t: String) -> i32 {
    let mut s_count = [0i32; 52];
    let mut t_count = [0i32; 52];

    for c in s.chars() {
        s_count[c as usize - 'a' as usize] += 1;
    }
    for c in t.chars() {
        t_count[c as usize - 'a' as usize] += 1;
    }

    let mut result: i32 = 0;
    for i in 0..52 {
        result += (s_count[i] - t_count[i]).abs()
    }
    result / 2
}

pub fn min_steps_improved(s: String, t: String) -> i32 {
    let mut count = [0i32; 52];
    let mut operations = 0;

    for b in s.bytes() {
        count[(b - ('a' as u8)) as usize] += 1;
    }

    for byte in t.bytes() {
        let idx = (byte - b'a') as usize;
        count[idx] -= 1;

        // if the count is negative for a certain letter we know we'll need to perform an operation
        // By doing this in the same loop we avoid another iteration to sum the values
        if count[idx] < 0 {
            operations += 1;
        }
    }
    operations
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn min_steps_example_1() {
        assert_eq!(min_steps("bab".to_string(), "aba".to_string()), 1);
    }
    #[test]
    fn min_steps_example_2() {
        assert_eq!(min_steps("leetcode".to_string(), "practice".to_string()), 5);
    }
    #[test]
    fn min_steps_example_3() {
        assert_eq!(min_steps("anagram".to_string(), "mangaar".to_string()), 0);
    }
}
