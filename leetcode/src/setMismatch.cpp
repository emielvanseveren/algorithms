#include "setMismatch.hpp"
#include "vector"

std::vector<int> Solution::findErrorNums(std::vector<int>&nums) {
    int n = nums.size();                                // anders steeds func nums.size() oproepen, hier 1x toewijzen sneller.
    int sum = n * (n + 1) / 2;                          // n + (n+1) / 2. Formule om som te vinden van standaard set (1 tem n).

    std::vector<int> res(2);

    /*
     * We maken een array van bools, telkens een getal gevonden is zetten we dat op true.
     * dit is sneller dan een set, want we kunnen hier meteen exacte geheugen alloceren die we maximaal zullen nodig hebben.
    */
    std::vector<bool> numInV(n +1, false);

    for (int num : nums) {
        sum -= num;
        if (numInV[num]) {res[0] = num;}
        numInV[num] = true;
    }
    res[1] = sum + res[0];
    return res;
}



