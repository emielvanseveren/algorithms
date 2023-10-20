pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|&x| x != val);
    return nums.len() as i32;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_remove_element_example_1() {
        let mut nums = vec![3, 2, 2, 3];
        assert_eq!(remove_element(&mut nums, 3), 2);
        assert_eq!(nums, vec![2, 2])
    }

    #[test]
    fn test_remove_element_example_2() {
        let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
        assert_eq!(remove_element(&mut nums, 2), 5);
        assert_eq!(nums, vec![0, 1, 3, 0, 4])
    }

    #[test]
    fn test_remove_element_example3() {
        let mut nums = vec![1];
        assert_eq!(remove_element(&mut nums, 1), 0);
        assert_eq!(nums, vec![])
    }

    #[test]
    fn test_remove_element_example4() {
        let mut nums = vec![3, 3];
        assert_eq!(remove_element(&mut nums, 3), 0);
        assert_eq!(nums, vec![])
    }
}
