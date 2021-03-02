#include <iostream>
#include <chrono>

#include "generators.h"
#include "medianwage.h"
#include "closestpair.h"

void assignment1_closest_pair()
{
  std::cout << "Exercise 1: Closest pair." << std::endl;

  int nrofPoints = 1000;

  std::vector<Point> points(nrofPoints);
  fillPVector(points, nrofPoints);
  
  auto start = std::chrono::high_resolution_clock::now();
  float min = closest_bf(points);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "-- Bruteforce        : The smallest distance is " << min << " | algorithm duration:  " << duration.count() << " ms" << std::endl; 

  start = std::chrono::high_resolution_clock::now(); 
  min = closest_optimal(points);
  stop = std::chrono::high_resolution_clock::now();

  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "-- Divide and conquer: The smallest distance is " << min << " | algorithm duration:  " << duration.count() << " ms" << std::endl;
}

void assignment2_median_wage()
{
  std::cout << "Exercise 2: Median wage." << std::endl;
  int nrofPoints = 100000;

  float median;

  std::vector<float> branchAf;
  std::vector<float> branchBf;
  
  fillVectors<float>(branchAf, branchBf, nrofPoints);

  auto start = std::chrono::high_resolution_clock::now(); 
  median = getMedian<float>(branchAf, branchBf);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Float    | The median is " << median << " | algorithm duration:  " << duration.count() << " ms" << std::endl;;  
  
  /** 
   * Once the employee class is provided with its operator overloaders, 
   * the code below can be uncommented as well as the unit tests in the testmedianwage source file 
   * to test if the function works with the Employee class. 
  */

  // Employee median_e;

  // std::vector<Employee> branchA;
  // std::vector<Employee> branchB;
  
  // fillVectors<Employee>(branchA, branchB, nrofPoints);

  // start = std::chrono::high_resolution_clock::now(); 
  // median_e = getMedian<Employee>(branchA, branchB);
  // stop = std::chrono::high_resolution_clock::now();

  // duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  // std::cout << "Employee | The median is " << median_e.wage << " | algorithm duration:  " << duration.count() << " ms" << std::endl;
}

int main()  
{

  assignment1_closest_pair();

  //assignment2_median_wage();

  return 0;
}

