pub fn longest_common_prefix(strs: Vec<String>) -> String {
    if strs.len() == 1 {
        return strs[0].clone();
    }

    // You can compare fold with reduce in js.
    strs.iter().skip(1).fold(strs[0].clone(), |acc, x| {
        acc.chars()
            .zip(x.chars()) // Makes tuples of chars of lcp and a string.
            .take_while(|(x, y)| x == y) // Save tuples while the chars in the tuple are equal
            .map(|(x, _)| x) // Since they are identical we only need 1 side
            .collect()
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_longest_common_prefix_example_1() {
        assert_eq!(
            String::from("fl"),
            longest_common_prefix(vec![
                String::from("flower"),
                String::from("flow"),
                String::from("flight")
            ])
        )
    }
    #[test]
    fn test_longest_common_prefix_example_2() {
        assert_eq!(
            String::from(""),
            longest_common_prefix(vec![
                String::from("dog"),
                String::from("racecar"),
                String::from("car")
            ])
        )
    }
}
