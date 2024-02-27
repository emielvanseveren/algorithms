// Take away the sum we started from the left side
// We calculate the right sum and left sum
// if left == right, center found
fn pivot_index(nums: Vec<i32>) -> i32 {
    let mut left_sum = 0;

    // currently idx = 0, so the total sum is the right sum
    let mut right_sum: i32 = nums.iter().sum();

    for (idx, n) in nums.iter().enumerate() {
        right_sum -= n;
        if left_sum == right_sum {
            return idx.try_into().unwrap();
        }
        left_sum += n
    }
    -1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn pivot_index_example_1() {
        assert_eq!(pivot_index(vec![1, 7, 3, 6, 5, 6]), 3);
    }

    #[test]
    fn pivot_index_example_2() {
        assert_eq!(pivot_index(vec![1, 2, 3]), -1);
    }

    #[test]
    fn pivot_index_example_3() {
        assert_eq!(pivot_index(vec![2, 1, -1]), 0);
    }
}
