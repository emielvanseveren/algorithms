#include "checkIfAStringContainsAllBinaryCodesOfSizeK.hpp"
#include "string"
#include "vector"
#include "bitset"

/*
 * The naive sololution would be to iterate through the possible binary strings and echck through the string (s) to see
 * if each one exists, but this would quickly tun into a TLE.
 *
 * We could work the other way around. And set all these bit positions to true.
 */

bool hasAllCodes(std::string s, int k){
    int len = s.size(), count = 1 << k;
    if(k>len) return false;
    int num = k > 1 ? stoi(s.substr(len - k + 1), 0, 2) << 1 : 0;

    std::vector<bool> seen(count, false);
    for (int i = len - k; ~i; i--) {
        num = (((s[i] - '0') << k) + num) >> 1;
        if (!seen[num]) seen[num] = true, count--;
        if (!count) return true;
        if (i < count) return false;
    }
    return false;
}

// a bitset is more efficient both memory and performance wise than a vector of booleans.
bool hasAllCodesWithBitSet(std::string s, int k){
    int len = s.size(), count = 1 << k;
    if(k>len) return false;
    int num = k > 1 ? stoi(s.substr(len - k + 1), 0, 2) << 1 : 0;

    std::bitset<400> seen;
    for(int i=len-k; ~i;i--){
        num = (((s[i] - '0') << k) + num) >> 1;
        if (!seen[num]) seen[num] = true, count--;
        if (!count) return true;
        if (i < count) return false;
    }
    return false;
}