pub fn longest_valid_parentheses(s: String) -> i32 {
    let mut stack: Vec<i32> = Vec::new();
    let mut max = 0;

    // edge cases
    stack.push(-1);

    for (i, b) in s.bytes().enumerate() {
        match b {
            b'(' => stack.push(i as i32),
            b')' => {
                stack.pop();
                if stack.is_empty() {
                    stack.push(i as i32);
                } else {
                    max = std::cmp::max(max, i as i32 - stack.last().unwrap())
                }
            }
            _ => unreachable!("will always contain ( and )"),
        }
    }

    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn longest_valid_parentheses_example_1() {
        assert_eq!(longest_valid_parentheses(String::from("(()")), 2)
    }

    #[test]
    fn longest_valid_parentheses_example_2() {
        assert_eq!(longest_valid_parentheses(String::from(")()())")), 4)
    }

    #[test]
    fn longest_valid_parentheses_example_3() {
        assert_eq!(longest_valid_parentheses(String::from("()(()")), 2)
    }
}
