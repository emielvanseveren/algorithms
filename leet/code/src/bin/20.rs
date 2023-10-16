/* we can use a stack:
 * for each ([{ we push them onto the stack
 * for each )]} we pop from the stack and check if the popped element is its counterpart.
 */
pub fn valid_parentheses(s: String) -> bool {
    let mut stack: Vec<u8> = Vec::new();
    s.as_bytes().iter().all(|b| match b {
        b'}' => stack.pop() == Some(b'{'),
        b']' => stack.pop() == Some(b'['),
        b')' => stack.pop() == Some(b'('),
        b'(' | b'[' | b'{' => {
            stack.push(*b);
            true
        }
        _ => false,
    }) && stack.is_empty()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_valid_parentheses_example_1() {
        // should be true
        assert!(valid_parentheses(String::from("()")))
    }

    #[test]
    fn test_valid_parentheses_example_2() {
        // should be true
        assert!(valid_parentheses(String::from("()[]{}")))
    }

    #[test]
    fn test_valid_parentheses_example_3() {
        // should be false
        assert!(!valid_parentheses(String::from("(]")))
    }
}
