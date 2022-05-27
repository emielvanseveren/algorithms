// naive implementation
pub fn number_of_steps_naive(num: i32) -> i32 {
    let mut num = num;
    let mut steps = 0;

    while num != 0 {
        if num % 2 == 0 {
            num /= 2;
        } else {
            num -= 1;
        }
        steps += 1;
    }
    steps
}

// with bit operations
pub fn number_of_steps_bits(num: i32) -> i32 {
    let mut num = num;
    let mut steps = 0;

    while num != 0 {
        steps += 1;

        // num XOR 1 == num+1
        if num ^ 1 == num + 1 {
            // right shift
            num >>= 1;
        } else {
            // left shift + not(num)
            num = (num << 1) + (!num);
        }
    }
    steps
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_number_of_steps_naive_example_1() {
        assert_eq!(number_of_steps_naive(14), 6);
    }

    #[test]
    fn test_number_of_steps_naive_example_2() {
        assert_eq!(number_of_steps_naive(8), 4);
    }

    #[test]
    fn test_number_of_steps_naive_example_3() {
        assert_eq!(number_of_steps_naive(123), 12);
    }

    #[test]
    fn test_number_of_steps_bits_example_1() {
        assert_eq!(number_of_steps_bits(14), 6);
    }

    #[test]
    fn test_number_of_steps_bits_example_2() {
        assert_eq!(number_of_steps_bits(8), 4);
    }

    #[test]
    fn test_number_of_steps_bits_example_3() {
        assert_eq!(number_of_steps_bits(123), 12);
    }
}
