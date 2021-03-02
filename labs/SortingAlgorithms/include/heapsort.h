#ifndef HEAPSORT
#define HEAPSORT

#include "algorithm"
#include "sortingalgorithm.h"

class HeapSort : public SortingAlgorithm
{
private:
public:
  void sort(std::vector<int> &v) const;
};

#endif
