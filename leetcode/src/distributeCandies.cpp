#include "distributeCandies.hpp"
#include "vector"
#include "unordered_set"
#include "algorithm"
#include "bitset"

// My solution using a normal unordered hashSet.
int Solution::distributeCandies(std::vector<int>& candyType){
    std::unordered_set<int> diff(candyType.begin(), candyType.end());
    return std::min(diff.size(), candyType.size()/2);
}

// Fastest solution using a bitset
int Solution::distributeCandiesWithBitSet(std::vector<int>&candies){
    std::bitset<200001> hash;
    for (int i: candies)
        hash.set(i + 100000);
    return std::min(hash.count(), candies.size() / 2);
}


/* Short exp bitset solution:
 * ############################
 * Working of a bitset<8>   =>  | 0 0 0 0 0 0 0 0 |       => When .set(2) fires the third bit is set from 0 to 1. | 0 0 0 0 0 1 0 0 |
 * 200 001 (why?)           =>  The input values can be from (-100 000) to 100 000 (given)
 * cant store negative bits so we add the max value and double the size of the bitset => 200 0001.&
*/