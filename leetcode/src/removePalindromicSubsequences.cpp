#include "removePalindromicSubsequences.hpp"
#include "string"

int removePalindromeSub(std::string s){

    if(!s.length())
        return 0;
    if(isPalindrome(s))
        return 1;
    return 2;
}

bool isPalindrome(std::string s){
    int l =0, h=s.length()-1;

    while(h>l){
        if(s[l++] != s[h--]){
            return false;
        }
    }
    return true;
}
