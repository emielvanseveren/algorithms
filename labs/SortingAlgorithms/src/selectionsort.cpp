#include "selectionsort.h"

void SelectionSort::sort(std::vector<int> &v) const
{
  /*
    we look for the maximum, when found, we move the element to the back of the array.
    Since everytime we do this the largest element is already at the back. We only
    loop again through the vectorSize-1 (hence i--);
  */
  for (int i = v.size() - 1; i > 0; i--)
  {
    int imax = i; // i will never exceed the boundaries
    for (int j = 0; j < i; j++)
    {
      if (v[j] > v[imax]) // everytime the number
      {
        imax = j;
      }
    }
    std::swap(v[i], v[imax]);
  }
};
