#pragma once
#include <vector>
#include <algorithm>

// A structure to represent a Point in 2D plane  
class Point  
{  
    public: 
    int x, y;  
};  

float dist(Point p1, Point p2);

float bruteForce(const std::vector<Point> &points, int n);

float closestPointsStrip(std::vector<Point> &strip, int size, float d);

float closestPoints(const std::vector<Point> &points, int n, int offset);

float closest_bf(const std::vector<Point> &points);
float closest_optimal(std::vector<Point> &points);