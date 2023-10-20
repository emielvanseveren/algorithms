// rotation 90 deg = reverse rows + transposition
pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    // reverse rows
    // 1 2 3        7 8 9
    // 4 5 6   ->   4 5 6
    // 7 8 9        1 2 3
    matrix.reverse();

    // transposing = swap matrix[i][j] with matrix[j][i]
    // 7 8 9        7 4 1
    // 4 5 6        8 5 2
    // 1 2 3        9 6 3
    for i in 1..matrix.len() {
        for j in 0..i {
            let t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_rotate_example_1() {
        let mut matrix = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
        rotate(&mut matrix);
        assert_eq!(matrix, vec![vec![7, 4, 1], vec![8, 5, 2], vec![9, 6, 3]]);
    }
}
