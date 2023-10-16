pub fn move_zeroes_naive(nums: &mut Vec<i32>) {
    let mut i = 0;
    for j in 0..nums.len() {
        if nums[j] != 0 {
            nums[i] = nums[j];
            i += 1;
        }
    }
    // replace the rest with 0
    for j in i..nums.len() {
        nums[j] = 0;
    }
}

// this is not in-place
pub fn move_zeroes_idiomatic(nums: &mut Vec<i32>) {
    let mut z = Vec::new();
    nums.retain(|x| {
        if *x != 0 {
            true
        } else {
            z.push(0);
            false
        }
    });
    &nums.append(&mut z);
}

pub fn move_zeroes_optimized(nums: &mut Vec<i32>) {
    let mut last_non_zero = 0;

    for i in 0..nums.len() {
        if nums[i] != 0 {
            if i != last_non_zero {
                nums.swap(i, last_non_zero);
            }
            last_non_zero += 1;
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn move_zeroes_example_1() {
        let mut naive = vec![0, 1, 0, 3, 12];
        move_zeroes_naive(&mut naive);
        assert_eq!(naive, vec![1, 3, 12, 0, 0]);

        let mut idiomatic = vec![0, 1, 0, 3, 12];
        move_zeroes_idiomatic(&mut idiomatic);
        assert_eq!(idiomatic, vec![1, 3, 12, 0, 0]);

        let mut optimized = vec![0, 1, 0, 3, 12];
        move_zeroes_optimized(&mut optimized);
        assert_eq!(optimized, vec![1, 3, 12, 0, 0]);
    }
    #[test]
    fn move_zeroes_example_2() {
        let mut naive = vec![0];
        move_zeroes_naive(&mut naive);
        assert_eq!(naive, vec![0]);

        let mut idiomatic = vec![0];
        move_zeroes_idiomatic(&mut idiomatic);
        assert_eq!(idiomatic, vec![0]);

        let mut optimized = vec![0];
        move_zeroes_optimized(&mut optimized);
        assert_eq!(optimized, vec![0]);
    }
}
