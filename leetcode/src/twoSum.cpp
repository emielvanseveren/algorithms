#include "twoSum.hpp"
#include "vector"
#include "unordered_map"

/* Brute force approach
 * get element from vector,
*/
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
    }
    return {0,0};
}

/*
 * Time complexity: O(n²) (For each element, we try to find its complement by looping through the rest of the array
 *                  which takes O(n). => O(n²)).
 * Space complexity: O(1)
*/

/* TWO-PASS HASH TABLE APPROACH (leetcode)
 * To improve our run time complexity, we need a more efficient way to check if the complement exists in the array.
 * If the complement exists, we need to look up its index. What is the best way to maintain a mapping of each element in
 * the array to its index? A hash table. We reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed.
 * A hash table is built exactly for this purpose, it supports fast look up in near constant time. I say "near" because
 * if a collision occurred, a look up could degenerate to O(n)O(n) time. But look up in hash table should be amortized
 * O(1)O(1) time as long as the hash function was chosen carefully. A simple implementation uses two iterations. In the
 * first iteration, we add each element's value and its index to the table. Then, in the second iteration we check if
 * each element's complement (target - nums[i]target−nums[i]) exists in the table. Beware that the complement must not
 * be nums[i]nums[i] itself!
*/

/*
 *  Dutch interpretation: We weten dat een bepaald getal slechts opgeteld kan worden met exact 1 ander getal om het target getal uit te komen
 *  In plaats van alle getallen te overlopen, maken we een hashtable van alle elementen. Ipv vooraf eerst een hash te maken van alle elementen
 *  voegen we een element toe telkens we de hash overlopen.
 */

std::vector<int> twoSumHashTable(std::vector<int>& nums, int target){
    std::unordered_map<int, int> hash;
    for(int i=0;;++i){
        auto it = hash.find(target - nums[i]);
        if (it != hash.end())
            return std::vector<int> {it->second, i};
        hash[nums[i]] = i;
    }
}

/* Solution:
 *  Time complexity: we loop elements only once (at most) => O(n), since a lookup is O(1).
 *  Space comlexity: O(n). We need to save all elements at most.
*/