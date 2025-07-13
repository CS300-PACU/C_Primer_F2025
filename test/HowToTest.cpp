#include <gtest/gtest.h>

#include "../include/howToTest.h"

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

