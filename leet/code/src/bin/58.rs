pub fn length_of_last_word(s: String) -> i32 {
    match s.split_whitespace().last() {
        Some(word) => word.len() as i32,
        None => 0,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_length_of_last_word_example_1() {
        assert_eq!(length_of_last_word("Hello World".to_string()), 5);
    }
    #[test]
    fn test_length_of_last_word_example_2() {
        assert_eq!(
            length_of_last_word("   fly me   to   the moon  ".to_string()),
            4
        );
    }

    #[test]
    fn test_length_of_last_word_example_3() {
        assert_eq!(length_of_last_word("luffy is still joyboy".to_string()), 6);
    }
}
