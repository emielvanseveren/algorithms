pub fn str_str(haystack: String, needle: String) -> i32 {
    if needle.is_empty() {
        return 0;
    }

    let haystack = haystack.as_bytes();
    let needle = needle.as_bytes();

    for i in 0..haystack.len() {
        if haystack[i] == needle[0] {
            if i + needle.len() > haystack.len() {
                return -1;
            }

            let mut found = true;
            for j in 1..needle.len() {
                if haystack[i + j] != needle[j] {
                    found = false;
                    break;
                }
            }

            if found {
                return i as i32;
            }
        }
    }
    -1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_find_index_first_occurrence_example_1() {
        assert_eq!(str_str("sadbutsad".to_string(), "sad".to_string()), 0);
    }
    #[test]
    fn test_find_index_first_occurrence_example_2() {
        assert_eq!(str_str("leetcode".to_string(), "leeto".to_string()), -1);
    }
}
