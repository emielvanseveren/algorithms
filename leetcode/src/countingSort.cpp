#include "countingSort.hpp"
#include "vector"

std::vector<int> sort(std::vector<int> &v, int min, int max){

    // step 1 create frequency table. // we could also create a memset
    std::vector<int> freq(max+1, 0);
    std::vector<int> output(v.size());


    for(int i=0; i<v.size(); i++){
        freq[v[i]]++;
    }

    // cumulative frequency
    for(int i=1; i<freq.size();i++){
       freq[i] = freq[i] + freq[i-1];
    }

    for(int i=0; i<v.size();i++){
        output[freq[v[i]]] = v[i];
        freq[v[i]]--;
    }
    return output;
}
