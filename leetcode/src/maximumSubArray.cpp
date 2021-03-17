#include "maximumSubArray.hpp"
#include "vector"
#include "algorithm"
#include "limits.h"

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * Some properties:
 * - If the array contains all non-negative numbers. The sum is equal to the entire array.
 * - If the array contains all negative numbers. The sum is equal to the smallest number, or an empty array if permitted.
 * - It is possible that several sub arrays have the same maximum sum.
 *
 * - Initially we could do this by creating every possible subarray and compare all of these subarrays (brute force). but this is O(n²) AKA slow.
 * - A faster way is to use [KADANE'S ALGORITHM]. (Great resources: https://www.youtube.com/watch?v=86CQq3pKSUw)
 * - Another solution would be to reduce using shortest path algo.
 *
 * Quick explanation of Kadane's algorithm:
 * We only compare the max of all previous elements + current element and the current element.
 * If the previous elements + current elements is larger than the current element, this is the new sum. otherwise the current element is the new max/sum.
 *
 *
 * example: arr=[-2,1,-3,4,-1,2]
 * first iteration:
 *      sum = -2
 *      max = -2
 *
 *      sum = max(-2,1, 1) = 1
 *      max = max(-2,1) = 1     => new max is 1
 *
 *      The following iteration we only compare this max + current element with the current element.
 */

/** non recursive O(n) */
int maximumSubArray(std::vector<int>& nums){
    // We don't need to iterate over the first element (only one element, so in this case we can set this value to both the max and the sum.)
    int sum = nums[0], max = nums[0];
    for(int i=1; i<nums.size(); i++){
        sum = std::max(sum + nums[i], nums[i]);
        max = std::max(max, sum);
    }
    return max;
}

/** Recursive (divide and conquer solution)
 * Great resource for recursive solution: https://www.youtube.com/watch?v=yBCzO0FpsVc
 * We divide the array in 2 parts (line in the middle)
 * This results in 3 possible cases:
 *  - The subset is on the left of the line => recursive call
 *  - The subset is on the right of the line => recursive call
 *  - The subset is crossing the line.
 *
 *  We take the max of these 3 cases.
 *
 *  Divide and conquer:
 *  - A basic return, that ends the recursion => when there is only 1 element left.
 *  - 2 recursive solutions (based on the cases above)
 */

// l=left, r=right
int maximumSubArrayDaQ(std::vector<int>& nums, int l, int r){
    if(l==r) {
        return nums[l];
    }
    int m = (l+r)/2;            // (l+r)/2 could give an overflow if the array is very large (if l+r is larger than MAX_INT).
    // INTERESTING: you can compare more than 2 elements using an initializer list (requires algorithm header and C++11 standard)
    return std::max({maximumSubArrayDaQ(nums, l, m), maximumSubArrayDaQ(nums, m + 1, r),maximumSubArrayCrossing(nums, l, m, r)});
}

/** We know both the start and the end of each side of the crossing subset.
 *  So we start from the center and go to the left
 *  we start from the center and go to the right.
 *
 *  l=low, m=mid,h=high
 */
int maximumSubArrayCrossing(std::vector<int>& nums, int l, int m, int r){
    int sum = 0;
    int lSum = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum = sum + nums[i];
        if (sum > lSum)
            lSum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int rSum = INT_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum = sum + nums[i];
        if (sum > rSum)
            rSum = sum;
    }

    return std::max({lSum+ rSum, lSum, rSum});
}

