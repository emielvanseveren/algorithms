#include "heapsort.h"
#include "algorithm"

void HeapSort::sort(std::vector<int> &v) const
{
  // build-in c++ heap implementation.
  std::make_heap(v.begin(), v.end()); // since a heap can be saved in an array, it will just rearrange the given vector.
  // the vector is now a heap.
}