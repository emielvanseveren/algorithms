use std::collections::HashMap;

// potential improvement:
//
// Since We know we are only working with ascii characters we could use an array for a-z and A-Z
// instead of a hashmap.
pub fn min_window(s: String, t: String) -> String {
    // early exit for empty string
    if t == "" {
        return String::new();
    }

    let mut t_freq = HashMap::new();
    for &c in t.as_bytes() {
        *t_freq.entry(c).or_insert(0) += 1;
    }

    let mut s_freq = HashMap::new();
    let required = t_freq.len();
    let mut formed = 0;

    let mut ans = (usize::MAX, 0, 0);
    let mut l = 0;
    let mut r = 0;

    let s_bytes = s.as_bytes();
    while r < s.len() {
        let char = s_bytes[r];
        *s_freq.entry(char).or_insert(0) += 1;

        if t_freq.contains_key(&char) && t_freq.get(&char) == s_freq.get(&char) {
            formed += 1;
        }

        while l <= r && formed == required {
            let char = s_bytes[l];

            if r - l + 1 < ans.0 {
                ans = (r - l + 1, l, r);
            }

            s_freq.entry(char).and_modify(|e| *e -= 1);
            if t_freq.contains_key(&char)
                && s_freq.get(&char).unwrap_or(&0) < t_freq.get(&char).unwrap()
            {
                formed -= 1;
            }

            l += 1;
        }

        r += 1;
    }

    if ans.0 == usize::MAX {
        String::new()
    } else {
        s[ans.1..=ans.2].to_string()
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_min_window_example_1() {
        assert_eq!(
            min_window("ADOBECODEBANC".to_string(), "ABC".to_string()),
            "BANC".to_string()
        );
    }
    #[test]
    fn test_min_window_example_2() {
        assert_eq!(
            min_window("a".to_string(), "a".to_string()),
            "a".to_string()
        );
    }

    #[test]
    fn test_min_window_example_3() {
        assert_eq!(
            min_window("a".to_string(), "aa".to_string()),
            "".to_string()
        );
    }
    #[test]
    fn test_min_window_example_4() {
        assert_eq!(
            min_window("abc".to_string(), "ac".to_string()),
            "abc".to_string()
        );
    }
    #[test]
    fn test_min_window_example_5() {
        assert_eq!(
            min_window("bbaa".to_string(), "aba".to_string()),
            "baa".to_string()
        );
    }
}
