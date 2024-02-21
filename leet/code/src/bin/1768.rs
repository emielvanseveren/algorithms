fn merge_alternately_idiomatic(word1: String, word2: String) -> String {
    // combine 2 iterators.
    // zip stops when the shortest iterator is exhausted
    word1
        .chars()
        .zip(word2.chars())
        .fold(String::new(), |mut acc, (c1, c2)| {
            acc.push(c1);
            acc.push(c2);
            acc
        })
        + if word1.len() > word2.len() {
            &word1[word2.len()..]
        } else {
            &word2[word1.len()..]
        }
}

fn merge_alternately(word1: String, word2: String) -> String {
    // Pre-allocate
    let mut result = String::with_capacity(word1.len() + word2.len());

    let mut word1 = word1.chars();
    let mut word2 = word2.chars();

    loop {
        match (word1.next(), word2.next()) {
            (Some(c1), Some(c2)) => {
                result.push(c1);
                result.push(c2);
            }
            (Some(c1), None) => {
                result.push(c1);
            }
            (None, Some(c2)) => {
                result.push(c2);
            }
            (None, None) => break,
        }
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn merge_alternately_example_1() {
        assert_eq!(
            merge_alternately("abc".to_string(), "pqr".to_string()),
            "apbqcr".to_string()
        );
        assert_eq!(
            merge_alternately_idiomatic("abc".to_string(), "pqr".to_string()),
            "apbqcr".to_string()
        )
    }

    #[test]
    fn merge_alternately_example_2() {
        assert_eq!(
            merge_alternately("ab".to_string(), "pqrs".to_string()),
            "apbqrs".to_string()
        );
        assert_eq!(
            merge_alternately_idiomatic("ab".to_string(), "pqrs".to_string()),
            "apbqrs".to_string()
        )
    }

    #[test]
    fn merge_alternately_example_3() {
        assert_eq!(
            merge_alternately("abcd".to_string(), "pq".to_string()),
            "apbqcd".to_string()
        );
        assert_eq!(
            merge_alternately_idiomatic("abcd".to_string(), "pq".to_string()),
            "apbqcd".to_string()
        );
    }
}
