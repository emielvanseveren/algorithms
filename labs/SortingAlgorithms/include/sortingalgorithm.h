#ifndef __SORTINGALGORITHM
#define __SORTINGALGORITHM

#include <vector>

class SortingAlgorithm{
    public:
	    // Single virtual method, sort the provided vector<T>
        virtual void sort(std::vector<int> &v) const =0;
        virtual ~SortingAlgorithm(){};
};


#endif 
