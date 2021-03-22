#include "sort.hpp"
#include "algorithm"

bool is_sorted(std::vector<int> &data) {
    return std::is_sorted(data.begin(), data.end());
}