#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "sortingalgorithm.h"
#include "algorithm"

class InsertionSort : public SortingAlgorithm
{
public:
  void sort(std::vector<int> &v) const;
};

#endif
