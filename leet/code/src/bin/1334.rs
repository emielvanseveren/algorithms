// this looks like floyd warshall (all pairs shortest path)

pub fn find_the_city(n: i32, edges: Vec<Vec<i32>>, distance_threshold: i32) -> i32 {
    // if we use i32::max, sum of two distances could overflow.
    let inf = 1_000_000_000;
    let distance: Vec<Vec<i32>> = vec![vec![inf; n as usize]; n as usize];

    // Fill initial distance matrix
    let distance = edges.iter().fold(distance, |mut distance, edge| {
        let (from, to, weight) = (edge[0] as usize, edge[1] as usize, edge[2]);
        distance[from][to] = weight;
        distance[to][from] = weight;
        distance
    });

    // Floyd Warshall update distance matrix
    let distance = (0..n as usize).fold(distance, |mut distance, k| {
        (0..n as usize).for_each(|i| {
            (0..n as usize).for_each(|j| {
                distance[i][j] = distance[i][j].min(distance[i][k] + distance[k][j]);
            });
        });
        distance
    });

    // Find the city with the smallest number of reachable cities
    (0..n as usize)
        .fold((0, n as usize), |(city, min), i| {
            let reachable = distance[i]
                .iter()
                .enumerate()
                // ignore the distance to itself.
                .filter(|(idx, d)| **d <= distance_threshold && *idx != i)
                .count();

            // keep the city with the smallest number of reachable cities
            if reachable <= min && i >= city {
                (i, reachable)
            } else {
                (city, min)
            }
        })
        .0 as i32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1334() {
        assert_eq!(
            find_the_city(
                4,
                vec![vec![0, 1, 3], vec![1, 2, 1], vec![1, 3, 4], vec![2, 3, 1]],
                4
            ),
            3
        );
        assert_eq!(
            find_the_city(
                5,
                vec![
                    vec![0, 1, 2],
                    vec![0, 4, 8],
                    vec![1, 2, 3],
                    vec![1, 4, 2],
                    vec![2, 3, 1],
                    vec![3, 4, 1]
                ],
                2
            ),
            0
        );
    }
}
