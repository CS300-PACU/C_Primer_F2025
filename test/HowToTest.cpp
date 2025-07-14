#include <gtest/gtest.h>

extern "C" {

	#include "../include/howToTest.h"

}

#define SIZE 10
#define LARGE_SIZE 100


TEST (TestSuite, TestIncreasingValues) {
  int aIncreasing[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ (aIncreasing[SIZE-1], findTheMaxInAnArray(aIncreasing, SIZE));
}

TEST (TestSuite, TestDecreasingValues) {
  int aDecreasing[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ (aDecreasing[0], findTheMaxInAnArray(aDecreasing, SIZE));
}

TEST (TestSuite, TestAtMid) {
  int aMidMax[SIZE] = {10, 1, 8, 17, 5, 100, 14, 30, 21, 11};
  EXPECT_EQ (aMidMax[5], findTheMaxInAnArray(aMidMax, SIZE));
}

TEST (TestSuite, TestCircleRadius) {
	Circle sCirc;
	const double RADIUS = 300.0;
	double radius;

	EXPECT_TRUE (circSetRadius(&sCirc, RADIUS));

	EXPECT_TRUE (circGetRadius(&sCirc, &radius));
	EXPECT_EQ (radius, RADIUS);
}

TEST (TestSuite, TestCircleArea) {
	Circle sCirc;
	const double RADIUS = 300.0;
	double area;

	EXPECT_TRUE (circSetRadius(&sCirc, RADIUS));

	EXPECT_TRUE (circGetArea(&sCirc, &area));
	EXPECT_EQ (area, M_PI * RADIUS * RADIUS);
}

TEST (TestSuite, TestCircleInvalidRadius) {
	Circle sCirc;

	EXPECT_FALSE (circSetRadius(&sCirc, -1.1));
	EXPECT_FALSE (circSetRadius(&sCirc, -0.1));
}

TEST (TestSuite, TestCircleInvalidParams) {
	Circle sCirc;
	double area;

	EXPECT_DEATH(circGetArea(&sCirc, NULL), ".*");
	EXPECT_DEATH(circGetArea(NULL, &area), ".*");
	EXPECT_DEATH(circGetArea(NULL, NULL), ".*");
}

//TEST (TestSuite, ExpectException) {
//  EXPECT_THROW( methodThatThrows( 'A'), std::invalid_argument);
//}

//TEST (TestSuite, ExpectTerminate) {
//  // expect exit with code 1
//  EXPECT_EXIT(methodThatCallsExit(-1), testing::ExitedWithCode(EXIT_FAILURE), ".*");
//  // expect any nonzero exit code
//  EXPECT_DEATH(methodThatCallsExit(-100), ".*");
//}


//https://stackoverflow.com/a/22737849
// cmake --build build 
// build/test/TestsToRun
// TestsToRun is from CMakeLists.txt line 5
//    set(This TestsToRun)
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

