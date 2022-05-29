// This can also be solved with dynamic programming but cba.
pub fn climb_stairs(n: i32) -> i32 {
    // base case
    if n <= 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }

    if n == 2 {
        return 2;
    }

    let mut one_step_before = 2;
    let mut two_steps_before = 1;
    let mut all_ways = 0;

    for _ in 2..n {
        all_ways = one_step_before + two_steps_before;
        two_steps_before = one_step_before;
        one_step_before = all_ways;
    }
    all_ways
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_climb_stairs_example_1() {
        assert_eq!(climb_stairs(2), 2);
    }

    #[test]
    fn test_climb_stairs_example_2() {
        assert_eq!(climb_stairs(3), 3);
    }
}
