#include <algorithm>
#include "encodeAndDecodeTinyUrl.hpp"
#include "string"


/* Before I created this exercise I had no idea how tiny urls work so here is my interpretation.
 *
 * A URL can be both, numbers, small letters and capital letters. so instead of base 10 (O-10) or base 26 (letters)
 * we can create a base of 26+26+10 = 62.
 *
 */

std::string encode(std::string longUrl){
    char b[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string base62;

}

std::string decode(std::string shortUrl){

}