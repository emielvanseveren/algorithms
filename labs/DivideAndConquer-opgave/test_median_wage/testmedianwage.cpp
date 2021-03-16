#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "generators.h"

 TEST_CASE("Employee class operator overloaders test", "[MedianWage]"){

 	Employee one = {1650.0f};
 	Employee two = {2030.0f};
     Employee three = {1650.0f};

 	REQUIRE((one + two).wage == 3680.0f);
 	REQUIRE((two - one).wage == 380.0f);
 	REQUIRE((two / 2).wage == 1015.0f);
 	REQUIRE((one < two) == true);
 	REQUIRE((one <= three) == true);

 }

 TEST_CASE("Final median wage test", "[MedianWage]"){
 	std::vector<float> branchAf = {3, 7, 8, 9, 12, 30, 40, 65};
   	std::vector<float> branchBf = {5, 8, 10, 20, 32, 64};

 	float median = getMedian<float>(branchAf, branchBf);

 	REQUIRE(median == 11.0f);
 }
