#include <cmath>
#include <cfloat>
#include "closestpair.h"
#include <iostream>

/**
 * A utility function to find the distance between two points. 
 */
float dist(Point p1, Point p2)  
{
    // Distance between 2 points. sqrt((x1-x2)² + (y1-y2)^2)
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y,2));
}

/**
 * A brute force method to return the smallest distance between two points in the point vector.
 */ 
float bruteForce(const std::vector<Point> &points, int n) {
    // We can do this by comparing each point with all other points and return those that are closest together, O(n²) => double loop.
    float minDistance = dist(points[0], points[1]);

    for(int i=0; i<n-1; i++){
        for(int j=1; j<n;j++){
            if(i==j) continue;               // we dont compare points with themself.
            if(dist(points[i], points[j]) < minDistance){
                minDistance = dist(points[i], points[j]);
            }
        }
    }
    return minDistance;
}  

/**
 * A utility function to find the distance between the closest points of the strip of given size.
 * All points in strip are sorted according to the y coordinate.
 * The upperbound for the minimum distance is passed to the function as d. 
 * Note that this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times.
 */
float closestPointsStrip(std::vector<Point> &strip, int size, float d)
{
    // The points are all on one side of the line and sorted by y coordinate.
    float min = d;      // d is the maximum distance => so this is a great minimum.
    // sort by y coordinate
    std::sort(strip.begin(), strip.begin() + size, [](const Point &p1, const Point &p2){
        return p1.y < p2.y;
    });

    // compare each point with the point next to them
    for(int i=0; i< size; ++i){
        for(int j=i+1; j< size && strip[j].y - strip[i].y < min; ++j){
            if(dist(strip[i], strip[j]) < min){
                min = dist(strip[i], strip[j]);
            }
        }
    }
    return min;
}
/**
 * A recursive function to find the smallest distance. The vector points contains all points sorted according to x coordinate.
*/
float closestPoints(const std::vector<Point> &points, int n, int offset)  
{
    // we need to make a recursive loop here to divide until there are only 2 points in every strip. How can we divide?
    int mid = n/2;
    Point midPoint = points[offset+mid];

    // calculate the distance with the point on the left of that center point and the point to the right. The shortest distance is the center.
    float dl = closestPoints(points, mid, offset);
    float dr = closestPoints(points, n-mid, mid+offset);
    float d = std::min(dl,dr);

    std::vector<Point> strip(n);
    int j=0;
    for(int i=0; i<n; i++){
       if(abs(points[offset+i].x - midPoint.x) < d) {
           strip[j] = points[offset+i], j++;
       }
    }
    return std::min(d, closestPointsStrip(strip, j, d));
}

float closest_bf(const std::vector<Point> &points)  
{  
    return bruteForce(points, points.size());
}  

float closest_optimal(std::vector<Point> &points)  
{  
    // the 2D algorithm requires the points to be sorted by x-coordinate.
    std::sort(points.begin(), points.end(), [](const Point &p1, const Point &p2){
        return p1.x < p2.x;
    });
    return closestPoints(points, points.size(), 0);
}
