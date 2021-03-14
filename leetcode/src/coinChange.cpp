#include "coinChange.hpp"
#include "algorithm"


/*
    * 1 <= coins.length <= 12
    * 1 <= coins[i] <= 231 - 1
    * 0 <= amount <= 104
*/


/*
 * SOLVE THIS USING DYNAMIC PROGRAMMING AND DIVIDE AND CONQUER *
 */

int coinChange(std::vector<int>& coins, int amount){
    std::sort(coins.begin(), coins.end());

    if(amount==0) return 0;
    int i = coins.size()-1;
    int amountOfCoins= 0;

    while(i>=0 && amount){
        if(coins[i]>amount) {
            i--;
            continue;
        }

        int rest = amount % coins[i]; // dit is de rest
        int times = (amount-rest) / coins[i];
        amount -= times*coins[i];
        amountOfCoins += times;
        i--;
    }



    if(amount!=0) {

        return coinChange();
    }
    return amountOfCoins;
}
