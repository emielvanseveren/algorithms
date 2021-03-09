#include "gtest/gtest.h"
#include "designHashMap.hpp"

TEST(designHashMap, start){
    MyHashMap hashMap = MyHashMap(10000);
    hashMap.put(1,1);
    hashMap.put(2,2);
    ASSERT_EQ(hashMap.get(1), 1);
    ASSERT_EQ(hashMap.get(3), -1);

    hashMap.put(2,1);
    ASSERT_EQ(hashMap.get(2),1);

    hashMap.remove(2);
    ASSERT_EQ(hashMap.get(2), -1);

}