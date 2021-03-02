#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "sortingalgorithm.h"
#include "algorithm"

class SelectionSort : public SortingAlgorithm
{
public:
  void sort(std::vector<int> &v) const;
};

#endif