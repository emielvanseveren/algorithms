#pragma once 
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> 

#include "medianwage.h"
#include "closestpair.h"

template <class T>
void fillVectors(std::vector<T> &branchA, std::vector<T> &branchB, int numberofpoints)
{
    srand(time(0));

    int upperbound = 5000;
    int lowerbound = 1500;

    float split = ((float)(rand() % 100))/100.0f;
    
    for(int i=0; i < (int)(numberofpoints * split); i++)
    {   
        int random_wage = rand() % (lowerbound-upperbound) + lowerbound;
        T e = {(float)random_wage};

        branchA.push_back(e);
        
    }
    for(int i=0; i < (int)(numberofpoints * (1.0f - split)); i++)
    {   
        int random_wage = rand() % (lowerbound-upperbound) + lowerbound;

        T e = {(float)random_wage};
        branchB.push_back(e);
    }

    std::sort(branchA.begin(), branchA.end());
    std::sort(branchB.begin(), branchB.end());  
}

void fillPVector(std::vector<Point> &points, int numberofpoints)
{
    srand(time(0));
    
    for(int i=0; i < numberofpoints; i++)
    {   
        int random_x = rand() % 5000;
        int random_y = rand() % 5000;

        Point p = {random_x, random_y};

        points[i] = p;
    }
}