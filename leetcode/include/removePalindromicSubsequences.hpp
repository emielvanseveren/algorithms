#ifndef REMOVE_PALINDROMIC_SUBSEQUENCES_HPP
#define REMOVE_PALINDROMIC_SUBSEQUENCES_HPP
#include "string"

class Solution {
public:
    int removePalindromeSub(std::string s);
private:
    bool isPalindrome(std::string s);
};

#endif
