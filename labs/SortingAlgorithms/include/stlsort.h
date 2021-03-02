#ifndef STLSORT_H
#define STLSORT_H

#include "sortingalgorithm.h"

#include <algorithm>

class STLSort : public SortingAlgorithm
{
public:
	void sort(std::vector<int>& v) const;
};

#endif
