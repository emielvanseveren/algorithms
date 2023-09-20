pub fn binary_search(nums: Vec<i32>, target: i32) -> i32 {
    use std::cmp::Ordering;
    let (mut left, mut right) = (0, nums.len());
    while left < right {
        let mid = left + (right - left) / 2;
        match nums[mid].cmp(&target) {
            Ordering::Equal => return mid as i32,
            Ordering::Less => left = mid + 1,
            Ordering::Greater => right = mid,
        }
    }
    -1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_binary_search_example_1() {
        assert_eq!(binary_search(vec![-1, 0, 3, 5, 9, 12], 9), 4);
    }
    #[test]
    fn test_binary_search_example_2() {
        assert_eq!(binary_search(vec![-1, 0, 3, 5, 9, 12], 2), -1);
    }

    #[test]
    fn test_binary_search_example_3() {
        assert_eq!(binary_search(vec![5], -5), -1);
    }
    #[test]
    fn test_binary_search_example_4() {
        assert_eq!(binary_search(vec![2, 5], 0), -1);
    }
}
