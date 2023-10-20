pub fn unique_paths(m: i32, n: i32) -> i32 {
    // base cases
    if m == 0 && n == 0 {
        return 0;
    }
    if m == 1 && n == 1 {
        return 1;
    }
    unique_paths_recursive(m, n, 0, 0)
}

fn unique_paths_recursive(m: i32, n: i32, i: i32, j: i32) -> i32 {
    // base case
    if i == m - 1 && j == n - 1 {
        return 1;
    }
    // out of bounds
    if i >= m || j >= n {
        return 0;
    }

    // try path down and path right
    unique_paths_recursive(m, n, i + 1, j) + unique_paths_recursive(m, n, i, j + 1)
}

// this can be optimized using dynamic programming and memoization of paths
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_unique_paths_example_1() {
        assert_eq!(unique_paths(3, 7), 28);
    }
    #[test]
    fn test_unique_paths_example_2() {
        assert_eq!(unique_paths(3, 2), 3);
    }
}
