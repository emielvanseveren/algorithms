#include "threeSum.hpp"
#include "vector"
#include "unordered_map"
#include "algorithm"

/** Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * 3sum is an extension of 2sum. So we create every possible triplet followed by a 2sum.
 */

std::vector<std::vector<int>> Solution::threeSum(std::vector<int> &nums){
    std::vector<std::vector<int>> res;
    if(nums.empty()) return res;

    // we start off by creating a sorted vector.
    std::sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size()-2; i++){ // because we need 3 numbers
        if(i>0 && nums[i] == nums[i-1])  continue;
        //TODO: fix this
    }

    // A performance improvement we can make is because we sort the array, if the first element is larger than 0, we know we can't make a sum of 0.
    if(nums[0]>0) return res;
    std::unordered_map<int,int> hash; // create hashmap of all numbers
}
