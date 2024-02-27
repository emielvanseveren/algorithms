pub fn remove_stars(s: String) -> String {
    let mut stack = String::new();
    for c in s.chars() {
        if c == '*' {
            // if *, pop last char from stack
            stack.pop();
        } else {
            // add char to stack
            stack.push(c)
        }
    }
    stack
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn remove_stars_example_1() {
        assert_eq!(remove_stars("leet**cod*e".to_string()), "lecoe".to_string());
    }

    #[test]
    fn remove_stars_example_2() {
        assert_eq!(remove_stars("erase*****".to_string()), "".to_string());
    }
}
