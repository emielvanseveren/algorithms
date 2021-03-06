#include "reverseInteger.hpp"
#include "string"
#include "cstdlib"

/*
 * initial thought:
 * module 10, the remainder is the number
*/

int reverse(int x){
    std::string temp = "";
    bool isNegative;

    if(x<0){
        isNegative = true;
        x *=-1;
    } else {
        isNegative = false;
    }

    while(x!=0){
        int remainder = x % 10; // 123 => remainder 3
        temp += std::to_string(remainder);
        x = (x-remainder) / 10;
    }

    x = std::atoi(temp.c_str());
    if(isNegative){
        return -1*x;
    }
    return x;
}

