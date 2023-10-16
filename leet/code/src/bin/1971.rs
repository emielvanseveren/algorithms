use std::collections::{HashMap, HashSet};

pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
    if source == destination || edges.is_empty() {
        return true;
    }

    // create a neighbours list, each entry in the map contains a list of all its neighbours.
    let mut n_list = HashMap::with_capacity(n as usize);
    edges.iter().for_each(|e| {
        n_list.entry(e[0]).or_insert_with(Vec::new).push(e[1]);
        n_list.entry(e[1]).or_insert_with(Vec::new).push(e[0]);
    });

    // BFS implementation using stack
    let mut stack = n_list[&source].clone();
    let mut reached = HashSet::with_capacity(n as usize);
    while let Some(val) = stack.pop() {
        // we already checked the neighbours of this vertice
        if !reached.insert(val) {
            continue;
        }

        for &vertice in n_list[&val].iter() {
            match vertice == destination {
                true => return true,
                // we should check all the neighbours of a vertice since it is connected with the
                // source so it might be a path
                false => stack.push(vertice),
            }
        }
    }
    false
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_valid_path_example_1() {
        let edges = vec![vec![0, 1], vec![1, 2], vec![2, 0]];
        assert!(valid_path(3, edges, 0, 2));
    }

    #[test]
    fn test_valid_path_example_2() {
        let edges = vec![vec![0, 1], vec![0, 2], vec![3, 5], vec![5, 4], vec![4, 3]];
        assert!(valid_path(6, edges, 0, 5));
    }
}
