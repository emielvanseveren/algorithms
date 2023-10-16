use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(PartialEq, PartialOrd)]
struct NonNanF64(f64);
impl Eq for NonNanF64 {}
impl Ord for NonNanF64 {
    fn cmp(&self, other: &Self) -> Ordering {
        self.0.partial_cmp(&other.0).unwrap()
    }
}

pub fn max_probability(
    n: i32,
    edges: Vec<Vec<i32>>,
    succ_prob: Vec<f64>,
    start: i32,
    end: i32,
) -> f64 {
    let n = n as usize;
    let start = start as usize;
    let end = end as usize;

    let adjacency_list = {
        let mut res = vec![vec![]; n];
        for (edge, prob) in edges.into_iter().zip(succ_prob) {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            res[u].push((v, prob));
            res[v].push((u, prob));
        }
        res
    };

    let mut prob_start = vec![0.0; n];
    prob_start[start] = 1.0;

    let mut priority_queue: BinaryHeap<(NonNanF64, usize)> = BinaryHeap::new();
    priority_queue.push((NonNanF64(1.0), start));

    // as long as end node is not reached, continue
    while let Some((NonNanF64(prob), u)) = priority_queue.pop() {
        if u == end {
            return prob;
        }
        for &(v, to_v_prob) in &adjacency_list[u] {
            let next_prob = prob * to_v_prob;
            if next_prob > prob_start[v] {
                prob_start[v] = next_prob;
                priority_queue.push((NonNanF64(next_prob), v));
            }
        }
    }

    // Description states to return 0 if there is no path from start to end.
    0.0
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_1514() {
        assert_eq!(
            max_probability(
                3,
                vec![vec![0, 1], vec![1, 2], vec![0, 2]],
                vec![0.5, 0.5, 0.2],
                0,
                2
            ),
            0.25000
        );
        assert_eq!(
            max_probability(
                3,
                vec![vec![0, 1], vec![1, 2], vec![0, 2]],
                vec![0.5, 0.5, 0.3],
                0,
                2
            ),
            0.30000
        );
        assert_eq!(
            max_probability(3, vec![vec![0, 1]], vec![0.5], 0, 2),
            0.00000
        );
    }
}
