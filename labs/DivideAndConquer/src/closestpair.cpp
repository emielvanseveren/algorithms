#include <cmath>
#include <cfloat>
#include "closestpair.h"
#include <iostream>

/**
 * A utility function to find the distance between two points. 
 */
float dist(Point p1, Point p2)  
{  
    std::cout << "Distance function is not implemented yet." << std::endl;
    
    return 0.0f;
}  

/**
 * A brute force method to return the smallest distance between two points in the point vector.
 */ 
float bruteForce(const std::vector<Point> &points, int n)  
{  
    std::cout << "BruteForce is not implemented yet." << std::endl;

    return 0.0f;
}  

/**
 * A utility function to find the distance beween the closest points of the strip of given size.
 * All points in strip are sorted according to the y coordinate.
 * The upperbound for the minimum distance is passed to the function as d. 
 * Note that this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times.
 */
float closestPointsStrip(std::vector<Point> &strip, int size, float d)
{  
    std::cout << "ClosestPointsStrip function is not implemented yet." << std::endl;

    return 0.0f;
}  
/**
 * A recursive function to find the smallest distance. The vector points contains all points sorted according to x coordinate.
*/
float closestPoints(const std::vector<Point> &points, int n, int offset)  
{  
    std::cout << "ClosestPoints function is not implemented yet." << std::endl;

    return 0.0f;
}  

float closest_bf(const std::vector<Point> &points)  
{  
    return bruteForce(points, points.size());
}  

float closest_optimal(std::vector<Point> &points)  
{  
    
    return closestPoints(points, points.size(), 0); 
}  