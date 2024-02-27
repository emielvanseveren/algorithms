use std::f64::NEG_INFINITY;

fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
    let mut max: f64 = NEG_INFINITY;
    nums.windows(k.try_into().unwrap()).for_each(|w| {
        let avg = w.iter().sum::<i32>() as f64 / w.len() as f64;
        max = avg.max(max);
    });
    max
}

fn find_max_average_idiomatic(nums: Vec<i32>, k: i32) -> f64 {
    nums.windows(k as usize)
        .map(|w| w.iter().sum::<i32>())
        .max()
        .unwrap() as f64
        / k as f64
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn find_max_average_example_1() {
        assert_eq!(find_max_average(vec![1, 12, -5, -6, 50, 3], 4), 12.75000);
        assert_eq!(
            find_max_average_idiomatic(vec![1, 12, -5, -6, 50, 3], 4),
            12.75000
        );
    }
    #[test]
    fn find_max_average_example_2() {
        assert_eq!(find_max_average(vec![5], 1), 5.00000);
        assert_eq!(find_max_average_idiomatic(vec![5], 1), 5.00000);
    }
    #[test]
    fn find_max_average_example_3() {
        assert_eq!(find_max_average(vec![-1], 1), -1.00000);
        assert_eq!(find_max_average_idiomatic(vec![5], 1), 5.00000);
    }
}
