// Important to notice here is that you don't need to recalculate the entire sliding window
// Instead, sliding 1 position, we just need to check the first and last char.
fn max_vowels(s: String, k: i32) -> i32 {
    let k = k as usize;

    if s.len() < k {
        return 0;
    }

    fn is_vowel(c: &char) -> i32 {
        match c {
            'a' | 'e' | 'i' | 'o' | 'u' => 1,
            _ => 0,
        }
    }

    let mut max_vowels: i32;
    let mut current_vowels: i32;
    let chars: Vec<char> = s.chars().collect();

    // Initial window is special case because we check all chars if they are vowels.
    current_vowels = chars.iter().take(k).map(is_vowel).sum();
    max_vowels = current_vowels;

    // other windows
    for i in k..chars.len() {
        current_vowels += is_vowel(&chars[i]) - is_vowel(&chars[i - k]);
        max_vowels = max_vowels.max(current_vowels);
    }

    max_vowels
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn max_vowels_example_1() {
        assert_eq!(max_vowels("abciiidef".to_string(), 3), 3)
    }

    #[test]
    fn max_vowels_example_2() {
        assert_eq!(max_vowels("aeiou".to_string(), 2), 2)
    }

    #[test]
    fn max_vowels_example_3() {
        assert_eq!(max_vowels("leetcode".to_string(), 3), 2)
    }
}
