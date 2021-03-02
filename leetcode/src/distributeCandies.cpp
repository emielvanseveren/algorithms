#include "distributeCandies.hpp"
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <bitset>


// My solution using a normal unordered hashSet.
int distributeCandies(std::vector<int>& candyType){
    std::unordered_set<int> diff(candyType.begin(), candyType.end());
    return std::min(diff.size(), candyType.size()/2);
}

// Fastest solution using a bitset
int distributeCandiesWithBitSet(std::vector<int>&candies){
    std::bitset<200001> hash;
    for (int i: candies)
        hash.set(i + 100000);
    return std::min(hash.count(), candies.size() / 2);
}

// | 0  | 1  | 0  | 0  | 1  | 0 |          bitset.set(2)

// explanation bitset
// bitset
