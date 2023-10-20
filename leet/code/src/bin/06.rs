pub fn convert(s: String, num_rows: i32) -> String {
    // base case
    if num_rows == 1 {
        return s;
    }

    let (mut step1, mut step2);
    let len = s.len();
    let mut result = String::with_capacity(len);
    let chars = s.chars().collect::<Vec<char>>();

    for i in 0..num_rows {
        step1 = (num_rows - i - 1) * 2;
        step2 = i * 2;
        let mut pos = i as usize;
        if pos < len {
            result.push(chars[pos]);
            loop {
                pos += step1 as usize;
                if pos >= len {
                    break;
                }
                if step1 != 0 {
                    result.push(chars[pos]);
                }
                pos += step2 as usize;
                if pos >= len {
                    break;
                }
                if step2 != 0 {
                    result.push(chars[pos]);
                }
            }
        }
    }
    return result;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_zigzag_conversion_example_1() {
        assert_eq!(
            convert("PAYPALISHIRING".to_string(), 3),
            "PAHNAPLSIIGYIR".to_string()
        );
    }

    #[test]
    fn test_zigzag_conversion_example_2() {
        assert_eq!(
            convert("PAYPALISHIRING".to_string(), 4),
            "PINALSIGYAHRPI".to_string()
        )
    }
    fn test_zigzag_conversion_example_3() {
        assert_eq!(convert("A".to_string(), 1), "A".to_string())
    }
}
