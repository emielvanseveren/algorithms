use std::collections::HashMap;

// I think we can use a frequency map, whenever a certain index is 1.
// we know that element only exists once.
pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut freq: HashMap<i32, usize> = HashMap::new();

    for num in nums.into_iter() {
        let counter = freq.entry(num).or_insert(0);
        *counter += 1
    }

    // loop through freq map and find the one that only has 1 as value
    for (key, value) in freq.into_iter() {
        if value == 1 {
            return key;
        }
    }
    unreachable!("There is always a value that exists only once.")
}

// this solutions does not need to loop the entire freq map anymore.
// It does to however remove a lot of values, which makes it slower.
pub fn single_number_other(nums: Vec<i32>) -> i32 {
    let mut freq: HashMap<i32, usize> = HashMap::new();
    for num in nums {
        match freq.remove(&num) {
            // in case it does not exist yet it is added.
            None => {
                freq.insert(num, 1);
            }
            // in case it exists it is removed
            Some(_x) => {}
        };
    }
    // Eventually there is only 1 key left in the map, the one that only exists once.
    *freq.keys().next().unwrap()
}

/* other solutions:
* The hashmap does not have constant space
* - we can sort the array and the moment we find that 2 neighbours are different we found our
*  number. This however requires sorting => O(lg(n)*n)
*
* - We can use bitwise XOR operator
* The elements with freq=2 will result in 0. And the only element with freq=1 will generate the
* answer.
 */

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_single_number_example_1() {
        assert_eq!(single_number(vec![2, 2, 1]), 1);
    }

    #[test]
    fn test_single_number_example_2() {
        assert_eq!(single_number(vec![4, 1, 2, 1, 2]), 4);
    }

    #[test]
    fn test_single_number_example_3() {
        assert_eq!(single_number(vec![1]), 1);
    }

    #[test]
    fn test_single_number_other_example_1() {
        assert_eq!(single_number_other(vec![2, 2, 1]), 1);
    }

    #[test]
    fn test_single_number_other_example_2() {
        assert_eq!(single_number_other(vec![4, 1, 2, 1, 2]), 4);
    }

    #[test]
    fn test_single_number_other_example_3() {
        assert_eq!(single_number_other(vec![1]), 1);
    }
}
