use std::collections::VecDeque;

// this implementation is very slow when the sliding window is very big.
// Because we need to find the max in each window.
pub fn max_sliding_window_naive(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let windows = nums.windows(k as usize);
    let mut result = Vec::with_capacity(windows.len());

    for win in windows {
        result.push(*win.iter().max().unwrap());
    }
    result
}

// solution based on: https://cses.fi/book/book.pdf
pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
    nums.into_iter()
        .enumerate()
        .scan(VecDeque::new(), |q: &mut VecDeque<(usize, i32)>, (i, n)| {
            while !q.is_empty() && q.back().unwrap().1 <= n {
                q.pop_back();
            }
            q.push_back((i, n));
            if q.front().unwrap().0 + k as usize == i {
                q.pop_front();
            }
            Some(q.front().unwrap().1)
        })
        .skip(k as usize - 1)
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_max_sliding_window_example_1() {
        assert_eq!(
            max_sliding_window_naive(vec![1, 3, -1, -3, 5, 3, 6, 7], 3),
            vec![3, 3, 5, 5, 6, 7]
        );
        assert_eq!(
            max_sliding_window(vec![1, 3, -1, -3, 5, 3, 6, 7], 3),
            vec![3, 3, 5, 5, 6, 7]
        );
    }
    #[test]
    fn test_max_sliding_window_example_2() {
        assert_eq!(max_sliding_window_naive(vec![1], 1), vec![1]);
        assert_eq!(max_sliding_window(vec![1], 1), vec![1]);
    }
}
