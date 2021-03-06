#include "string"
#include "shortEncodingOfWords.hpp"
#include "vector"
#include "unordered_set"

/*
 * A valid encoding of an array of words is any reference string s and array of indices indices such that:

 * words.length == indices.length
 * The reference string s ends with the '#' character.
 * For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#'
 * character is equal to words[i]. Given an array of words, return the length of the shortest reference string s
 * possible of any valid encoding of words.
 *
 *
 * constraints:
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * words[i] consists of only lowercase letters.
 */

/* initial thoughts
 *  - Although the indices are given, we don't need to return them, we are only interested in the count.
 * */

int minimumLengthEncoding(std::vector<std::string> &words){
    std::unordered_set<std::string> s(words.begin(), words.end());
    for(std::string word : words){
        for(int i=1; i<word.length(); i++){
           s.erase(word.substr(i));
        }
    }
    int ans=0;
    for(std::string w: s){
        ans += w.length() + 1;
    }
    return ans;
}
