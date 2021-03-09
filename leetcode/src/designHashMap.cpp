#include "designHashMap.hpp"
#include "error.h"
#include "stdlib.h"
/*
 *
 *
 * creating an own hashmap => we take a certain key, and use a certain algo to create a hash
 * that key will be reset within the range of our array.
 *
 * The array itself can be set to 10000. Since that is the maximum amount of operations.
 * The elements itself can have identical keys. To solve this we will use coalesced chaining
 *
 * We don't need a special hash since the keys are integers in the range of 0-100_000.
 * A modulo 10_000 will do.
 *
*/

int MyHashMap::hash(int key) const {
    // the hash function will make sure the key is within the 0-10_000 range. (no string key so basic modulo)
    return abs(key) % size;
}

MyHashMap::MyHashMap(int size): size(size) {
    bucket = new Bucket[size];
}
MyHashMap::~MyHashMap() {
    delete [] bucket;
}

void MyHashMap::put(int key, int value) {
    int index = hash(key);

    // if the location is empty insert a new bucket in this location || the first element in the bucket has the key we are looking for
    if(bucket[index].used == false || bucket[index].key == key){
        bucket[index].used = true;
        bucket[index].val = value;
        bucket[index].key = key;
        return;
    }

    // if the first element does not have that key we should add the element to the back of the array.
    int pos = size-1; // -1 since the array is 0-9999.
    while(pos >=0 && bucket[pos].used == true && bucket[pos].key != key){
        pos--;
    }

    if(pos==-1){return;} // TODO: return fatal error. This means the hashtable has filled each location in the array. OVERFLOW ERROR.

    // an empty location is found. Create a new used bucket here.
    bucket[pos].key = key;
    bucket[pos].used = true;
    bucket[pos].val = value;

    while(bucket[index].next != -1){
        index = bucket[index].next;
    }
    bucket[index].next = pos;
}

int MyHashMap::get(int key) const {
    int index = hash(key);
    if(bucket[index].used == false && bucket[index].key == key){ // false
        return -1;
    }

    // now we need to find the correct location in the chain
    while(index !=-1 && bucket[index].key != key){ // if key does not exist
        index = bucket[index].next;
    }
    if(index==-1 || bucket[index].used == false){return -1;} // could be that the value is there the keys match but it has a soft remove.

    return bucket[index].val;
}

void MyHashMap::remove(int key) {
    int index = hash(key);

    while(bucket[index].next != -1 && bucket[index].key != key){
        index = bucket[index].next;
    }

    if(index==-1){return;} // this means the key was not found.
    bucket[index].used = false; // flag that soft removes the element.
}

/*
 * Soluton 2 (not memory efficient but fast for this specific case)

class MyHashMap {
private:
    const static int N = 1000001;
    int arr[N];
public:
    MyHashMap() {
        std::fill_n(m,N,-1) // Fill all with val -1 (faster than looping over the array)
        for (int i = 0; i < N; ++i) m[i] = -1;
    }
    void put(int key, int value) {
        arr[key] = value;
    }
    int get(int key) {
        return arr[key];
    }
    void remove(int key) {
        arr[key] = -1;
    }
};
 */


