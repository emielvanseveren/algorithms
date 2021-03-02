#include "shellsort.h"

/*
 ShellSort is a variation of Insertion Sort. In insertion sort, we move elemnts only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be **h-sorted** if all sublists of every h'th element is sorted.
*/

void ShellSort::sort(std::vector<int> &v) const
{
  for (int k = v.size(); k > 0; k /= 2)
  {
    for (int i = k; i < v.size(); i++)
    {
      int temp = std::move(v[i]);
      int j = i - k;
      while (j >= 0 && temp < v[j])
      {
        v[j + k] = std::move(v[j]);
        j -= k;
      }
      v[j + k] = std::move(temp);
    }
  }
}

/* common implementation

How do we pick a good k?







*/

/*
example with k =3

[7,6,8,9,3,2,10,5,1] k=4 (gap)
 7 - - - 3
   6 - - - 2
     8 - - - 10
       9 - - -- 5
                  3 (has already been used in the first comparison, so 1 is just left here and does not have to be compared)

[3,2,8,5,7,6,8,9,10,1]

we repeat this process until k=1.
*/