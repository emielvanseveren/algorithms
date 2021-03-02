#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template <class T>
void fillVectors(std::vector<T> &branchA, std::vector<T> &branchB, int numberofpoints)
{
  srand(time(0));

  int upperbound = 5000;
  int lowerbound = 1500;

  float split = ((float)(rand() % 100)) / 100.0f;

  for (int i = 0; i < (int)(numberofpoints * split); i++)
  {
    int random_wage = rand() % (lowerbound - upperbound) + lowerbound;
    T e = {(float)random_wage};

    branchA.push_back(e);
  }
  for (int i = 0; i < (int)(numberofpoints * (1.0f - split)); i++)
  {
    int random_wage = rand() % (lowerbound - upperbound) + lowerbound;

    T e = {(float)random_wage};
    branchB.push_back(e);
  }

  std::sort(branchA.begin(), branchA.end());
  std::sort(branchB.begin(), branchB.end());
}