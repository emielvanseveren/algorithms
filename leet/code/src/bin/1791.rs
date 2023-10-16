// A center node must appear in every edge.
// We check which node appears in both the first and the second edge.

fn find_center(edges: Vec<Vec<i32>>) -> i32 {
    match edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
        true => edges[0][0],
        false => edges[0][1],
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn find_center_example_1() {
        let input = vec![vec![1, 2], vec![2, 3], vec![4, 2]];
        assert_eq!(find_center(input), 2)
    }

    #[test]
    fn find_center_example_2() {
        let input = vec![vec![1, 2], vec![5, 1], vec![1, 3], vec![1, 4]];
        assert_eq!(find_center(input), 1)
    }
}
