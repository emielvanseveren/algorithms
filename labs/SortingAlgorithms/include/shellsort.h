#ifndef SHELLSORT
#define SHELLSORT

#include "sortingalgorithm.h"
#include "algorithm"

class ShellSort : public SortingAlgorithm
{
public:
  void sort(std::vector<int> &v) const;
};

#endif