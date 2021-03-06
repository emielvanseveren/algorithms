#ifndef TWO_SUM_HPP
#define TWO_SUM_HPP

#include "vector"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSumHashTable(std::vector<int>& nums, int target);
};
#endif