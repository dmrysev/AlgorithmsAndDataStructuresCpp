#include "algorithm/numeric.h"
#include <gtest/gtest.h>


namespace Algorithm::Numeric::Test {

TEST(Algorithm_Numeric, findSmallestPositiveMissingInteger) {
    ASSERT_EQ(findSmallestPositiveMissingInteger({}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({1}), 2);
    ASSERT_EQ(findSmallestPositiveMissingInteger({1,3,6,4,1,2}), 5);
    ASSERT_EQ(findSmallestPositiveMissingInteger({1,2,3}), 4);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1,-2}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-2,-1,0}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1,-2,1,3,4}), 2);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,2,3}), 4);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,1,2,2,4}), 3);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,2,3}), 4);
}

TEST(Algorithm_Numeric, findSmallestPositiveMissingInteger_random) {
    // ARRANGE
    std::vector<int> i1(200);
    std::generate(i1.begin(), i1.end(), [] () {
        static int i = -50;
        return i++;
    });
    std::remove(i1.begin(), i1.end(), 101);
    std::random_shuffle(i1.begin(), i1.end());

    // ACT/ASSERT
    ASSERT_EQ(findSmallestPositiveMissingInteger(i1), 101);
}

TEST(Algorithm_Numeric, findLargestBinaryGap) {
    ASSERT_EQ(findLargestBinaryGap(9), 2); // 1001
    ASSERT_EQ(findLargestBinaryGap(20), 1); // 10100
    ASSERT_EQ(findLargestBinaryGap(529), 4); // 1000010001
    ASSERT_EQ(findLargestBinaryGap(15), 0); // 1111
    ASSERT_EQ(findLargestBinaryGap(15), 0); // 1111
}

}
