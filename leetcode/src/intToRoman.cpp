#include <vector>
#include "intToRoman.hpp"
#include "string"
#include "unordered_map"

/* Constraints: numbers are between 1 and 3999 */
/*
 * Aftermath of why this is a very **BAD** solution.
 * We have to create the entire map for every translation. While there will be only one key-to-value translation for every map.
 * So a lot of unnecessary preprocessing and memory usage while it can be done in a few loops tackling the edge cases.
 */

std::string intToRoman(int num){
    std::string roman;
    int c = 1;

    // since we
    std::vector<std::unordered_map<int,std::string>> translations(
            {{{1,"I"},{2,"II"},{3, "III"},{4, "IV"},{5, "V"},{6, "VI"},{7, "VII"},{8, "VIII"},{9, "IX"},{10,"X"}},
            {{1,"X"},{2,"XX"},{3,"XXX"}, {4,"XL"},{5,"L"},{6,"LX"},{7,"LXX"},{8,"LXXX"}, {9,"XC"}},
            {{1,"C"},{2,"CC"},{3,"CCC"},{4,"CD"},{5,"D"}, {6, "DC"}, {7,"DCC"}, {8,"DCCC"}, {9,"CM"}},
            {{1, "M"},{2,"MM"},{3,"MMM"}}
    });
    while(num){
        int digit = num%10;
        num = (num-digit)/10;
        roman = translations.at(c-1)[digit] + roman;
        c++;
    }

    return roman;
}

/* fast solution
  string intToRoman(int num) {
        string roman;
        if (num >= 1000) {
            int m_count = num / 1000;
            roman.insert(roman.end(), m_count, 'M');
            num %= 1000;
        }
        if (num >= 900) {
            roman += "CM";
            num -= 900;
        }
        if (num >= 500) {
            roman += "D";
            num -= 500;
        }
        if (num >= 400) {
            roman += "CD";
            num -= 400;
        }
        if (num >= 100) {
            int c_count = num / 100;
            roman.insert(roman.end(), c_count, 'C');
            num %= 100;
        }
        if (num >= 90) {
            roman += "XC";
            num -= 90;
        }
        if (num >= 50) {
            roman += "L";
            num -= 50;
        }
        if (num >= 40) {
            roman += "XL";
            num -= 40;
        }
        if (num >= 10) {
            int x_count = num / 10;
            roman.insert(roman.end(), x_count, 'X');
            num %= 10;
        }
        if (num >= 9) {
            roman += "IX";
            num -= 9;
        }
        if (num >= 5) {
            roman += "V";
            num -= 5;
        }
        if (num >= 4) {
            roman += "IV";
            num -= 4;
        }
        if (num >= 1) {
            roman.insert(roman.end(), num, 'I');
        }
        return roman;
    }
 * */


