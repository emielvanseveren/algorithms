fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
    // Find the maximum number of candies
    // check if current candies + extra candies is greater than or equal to the maximum number of candies.

    let max = *candies.iter().max().unwrap();
    let mut result: Vec<bool> = Vec::with_capacity(candies.len());

    for candy in candies {
        result.push(candy + extra_candies >= max);
    }
    result
}

fn kids_with_candies_idiomatic(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
    let max = candies.iter().max().unwrap();
    let res = candies
        .iter()
        .map(|candy| *candy + extra_candies >= *max)
        .collect();
    res
}

#[cfg(test)]

mod tests {
    use super::*;

    #[test]
    fn kids_with_candies_example_1() {
        assert_eq!(
            kids_with_candies(vec![2, 3, 5, 1, 3], 3),
            vec![true, true, true, false, true]
        );

        assert_eq!(
            kids_with_candies_idiomatic(vec![2, 3, 5, 1, 3], 3),
            vec![true, true, true, false, true]
        );
    }

    #[test]
    fn kids_with_candies_example_2() {
        assert_eq!(
            kids_with_candies(vec![4, 2, 1, 1, 2], 1),
            vec![true, false, false, false, false]
        );
        assert_eq!(
            kids_with_candies_idiomatic(vec![4, 2, 1, 1, 2], 1),
            vec![true, false, false, false, false]
        );
    }

    #[test]
    fn kids_with_candies_example_3() {
        assert_eq!(
            kids_with_candies(vec![12, 1, 12], 10),
            vec![true, false, true]
        );
        assert_eq!(
            kids_with_candies_idiomatic(vec![12, 1, 12], 10),
            vec![true, false, true]
        );
    }
}
