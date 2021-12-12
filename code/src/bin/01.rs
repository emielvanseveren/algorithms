use std::collections::HashMap;

pub fn two_sum_naive(nums: Vec<i32>, target: i32) -> Vec<i32> {
    for (i, num) in nums.iter().enumerate() {
        for (j, num2) in nums.iter().enumerate() {
            if i != j && num + num2 == target {
                return vec![i.try_into().unwrap(), j.try_into().unwrap()];
            }
        }
    }
    unreachable!("The problem assumes that each input would have exactly one solution.");
}

// O(n), passes the vector only once.
pub fn two_sum_hash(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = HashMap::<i32, i32>::with_capacity(nums.len() + 8);
    for (idx, num) in nums.iter().enumerate() {
        if let Some(&index) = map.get(&(target - num)) {
            if index != idx as i32 {
                return vec![index, idx as i32];
            }
        }
        map.insert(*num, idx as i32);
    }
    unreachable!("The problem assumes that each input would have exactly one solution.");
}

fn main() {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_two_sum_example_1() {
        let nums = vec![2, 7, 11, 15];
        let target = 9;
        assert_eq!(two_sum_naive(nums.clone(), target), vec![0, 1]);
        assert_eq!(two_sum_hash(nums, target), vec![0, 1]);
    }
    #[test]
    fn test_two_sum_example_2() {
        let nums = vec![3, 4, 2];
        let target = 6;
        assert_eq!(two_sum_naive(nums.clone(), target), vec![1, 2]);
        assert_eq!(two_sum_hash(nums, target), vec![1, 2]);
    }
    #[test]
    fn test_two_sum_example_3() {
        let nums = vec![3, 3];
        let target = 6;
        assert_eq!(two_sum_naive(nums.clone(), target), vec![0, 1]);
        assert_eq!(two_sum_hash(nums, target), vec![0, 1]);
    }
}
