#include "missingNumber.hpp"
#include "vector"

int Solution::missingNumber(std::vector<int>&nums){
    int n = nums.size();
    int sum = n*(n+1)/2;

    for(int num: nums){
        sum -= num;
    }
    return sum;
}

/*
 * Solution:
 * Identical to the 'setMismatch' problem we have a standard set of 0 to n.
 * So we know the sum of all numbers is n*(n+1). Gauss formula!
 * if we just extract all the numbers we get the remaining number.
*/
