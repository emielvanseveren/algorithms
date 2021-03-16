#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "generators.h"
#include "closestpair.h"

TEST_CASE("Calculating distance between two points", "[ClosestPair]"){
	Point one = {1, 0},  two = {2, 3};
	float d = dist(one, two);
	Approx target = Approx(3.16228).epsilon(0.01);
	REQUIRE(d  == target);
}

TEST_CASE("Testing bruteforce function", "[ClosestPair]"){
	std::vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	float min = bruteForce(points, points.size());
	Approx target = Approx(1.41421).epsilon(0.01);
	REQUIRE(min == target);
}

TEST_CASE("Testing stripclosest function", "[ClosestPair]"){
	std::vector<Point> strip= {{2, 3}, {12, 30}, {7, 4}};
	int n = sizeof(strip) / sizeof(strip[0]); 
	float min = closestPointsStrip(strip, n , 10.0000f);
	Approx target = Approx(5.09902).epsilon(0.01);
	REQUIRE(min == target);
}

TEST_CASE("Final closest pair test", "[ClosestPair]"){
	std::vector<Point> points = {{267, 777}, {743, 98}, {196, 90}, {954, 350}, {307, 919}, {395, 98}, {196, 183}, {341, 105}, {802, 91}, {512, 255}, {9, 875}, {737, 920}, {665, 909}, {30, 527}, {115, 247}, {5, 383}, {24, 100}, {833, 572}, {190, 139}, {922, 850}, {59, 318}, {300, 255}, {853, 642}, {712, 655}, {85, 225}, {910, 94}, {452, 647}, {366, 118}, {556, 749}, {997, 24}, {996, 2}, {407, 372}, {102, 592}, {944, 645}, {731, 219}, {847, 142}, {889, 147}, {750, 742}, {141, 462}, {749, 226}};
	float min = closest_optimal(points);
	Approx target = Approx(19.31321).epsilon(0.01);
	REQUIRE(min == target);
}

