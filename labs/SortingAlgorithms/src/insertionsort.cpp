#include "insertionsort.h"

void InsertionSort::sort(std::vector<int> &v) const
{
  for (int i = 1; i < v.size(); i++)
  {
    int key = v[i];
    int j = i - 1;

    while (j >= 0 && key < v[j])
    {
      // everytime an element is larger than its precessor it is swapped, and compared again with its precessor, until it is either 0 or larger.
      std::swap(v[j], v[j + 1]);
      j--;
    }
  }
}
