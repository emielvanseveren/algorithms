pub fn break_palindrome(palindrome: String) -> String {
    let n = palindrome.len();

    // strings of length <=1 it is impossible to break the palindrome.
    if n <= 1 {
        return String::new();
    }

    let mut palindrome = palindrome.as_bytes().to_vec();

    // take half (excluding middle) and look for the first character that is not an a.
    // if found: replace with a,
    // if not: they must all be equal to a. so we should change the last character to b.
    match palindrome.iter_mut().take(n / 2).find(|b| **b != b'a') {
        Some(b) => *b = b'a',
        None => *palindrome.last_mut().unwrap() = b'b',
    }
    palindrome.into_iter().map(|b| b as char).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_break_palindrome_example_1() {
        assert_eq!(break_palindrome("abccba".to_string()), "aaccba".to_string());
    }

    #[test]
    fn test_break_palindrome_example_2() {
        assert_eq!(break_palindrome("a".to_string()), "".to_string());
    }
}
