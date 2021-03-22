#ifndef MAXIMUM_SUB_ARRAY_HPP
#define MAXIMUM_SUB_ARRAY_HPP

#include "vector"

class Solution {
public:
    int maximumSubArray(std::vector<int>& nums);
    int maximumSubArrayDaQ(std::vector<int>& nums, int l, int r);
    int maximumSubArrayCrossing(std::vector<int> &nums, int l, int m, int r);
};

#endif
