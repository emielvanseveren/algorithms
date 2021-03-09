#ifndef DESIGN_HASHMAP_HPP
#define DESIGN_HASHMAP_HPP

#include "vector"

struct Bucket {
    bool used = false;
    int key;
    int val;
    short int next = -1;
};

class MyHashMap {
public:
    MyHashMap(int size);
    ~MyHashMap();
    void put(int key, int value);
    int get(int key) const;
    void remove(int key);
private:
    int hash(int key) const;
    Bucket *bucket;
    short size;
};

#endif
