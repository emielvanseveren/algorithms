pub fn longest_substring_without_repeating_characters(s: String) -> i32 {
    let mut max_len: usize = 0;
    let mut pos: [usize; 128] = [0; 128];
    let mut start: usize = 0;

    for (end, ch) in s.chars().enumerate() {
        start = start.max(pos[ch as usize]);
        max_len = max_len.max(end - start + 1);
        pos[ch as usize] = end + 1;
    }
    return max_len as i32;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_longest_substring_without_repeating_characters_example_1() {
        assert_eq!(
            longest_substring_without_repeating_characters("abcabcbb".to_string()),
            3
        );
    }

    #[test]
    fn test_longest_substring_without_repeating_characters_example_2() {
        assert_eq!(
            longest_substring_without_repeating_characters("bbbbb".to_string()),
            1
        );
    }

    #[test]
    fn test_longest_substring_without_repeating_characters_example_3() {
        assert_eq!(
            longest_substring_without_repeating_characters("pwwkew".to_string()),
            3
        );
    }
}
