pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
    if n == 1 {
        return n;
    }

    let mut people: Vec<i32> = vec![0; n as usize];

    trust.iter().for_each(|pair| {
        people[(pair[0] - 1) as usize] -= 1;
        people[(pair[1] - 1) as usize] += 1;
    });

    people
        .iter()
        // only the person that has N-1 trust balance is trusted by everyone and trusts none.
        .position(|&num| num == n - 1)
        .map_or(-1, |i| (i + 1) as i32)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn find_judge_test_example_1() {
        assert_eq!(find_judge(2, vec![vec![1, 2]]), 2)
    }
    #[test]
    fn find_judge_test_example_2() {
        assert_eq!(find_judge(3, vec![vec![1, 3], vec![2, 3]]), 3);
    }
    #[test]
    fn find_judge_test_example_3() {
        assert_eq!(find_judge(3, vec![vec![1, 3], vec![2, 3], vec![3, 1]]), -1);
    }
    #[test]
    fn find_judge_test_example_4() {
        assert_eq!(find_judge(3, vec![vec![1, 2], vec![2, 3]]), -1);
    }
}
