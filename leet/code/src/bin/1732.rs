fn largest_altitude(gain: Vec<i32>) -> i32 {
    let mut curr = 0;

    let alt = gain
        .iter()
        .map(|g| {
            curr += g;
            curr
        })
        .max()
        .unwrap();

    alt.max(0)
}

fn largest_altitude_idiomatic(gain: Vec<i32>) -> i32 {
    // reducer which keeps state of previous and current max
    gain.iter()
        .fold((0, 0), |(mut prev, mut max), &g| {
            prev += g;
            max = max.max(prev);
            (prev, max)
        })
        .1
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn largest_altitude_example_1() {
        assert_eq!(largest_altitude(vec![-5, 1, 5, 0, -7]), 1);
        assert_eq!(largest_altitude_idiomatic(vec![-5, 1, 5, 0, -7]), 1);
    }

    #[test]
    fn largest_altitude_example_2() {
        assert_eq!(largest_altitude(vec![-4, -3, -2, -1, 4, 3, 2]), 0);
        assert_eq!(largest_altitude_idiomatic(vec![-4, -3, -2, -1, 4, 3, 2]), 0);
    }
}
