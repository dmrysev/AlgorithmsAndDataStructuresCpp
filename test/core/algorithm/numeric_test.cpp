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
    ASSERT_EQ(findLargestBinaryGap(0), 0); // 0000
    ASSERT_EQ(findLargestBinaryGap(9), 2); // 1001
    ASSERT_EQ(findLargestBinaryGap(20), 1); // 10100
    ASSERT_EQ(findLargestBinaryGap(15), 0); // 1111
    ASSERT_EQ(findLargestBinaryGap(529), 4); // 1000010001
}

TEST(Algorithm_Numeric, countDivisible) {
    ASSERT_EQ(countDivisible(0, 0, 1), 1);
    ASSERT_EQ(countDivisible(0, 1, 1), 2);
    ASSERT_EQ(countDivisible(0, 2, 1), 3);
    ASSERT_EQ(countDivisible(0, 3, 2), 2);
    ASSERT_EQ(countDivisible(1, 4, 2), 2);
    ASSERT_EQ(countDivisible(3, 3, 2), 0);
    ASSERT_EQ(countDivisible(3, 6, 2), 2);
    ASSERT_EQ(countDivisible(0, 4, 2), 3);
    ASSERT_EQ(countDivisible(5, 5, 5), 1);
    ASSERT_EQ(countDivisible(5, 6, 5), 1);
    ASSERT_EQ(countDivisible(5, 6, 6), 1);
    ASSERT_EQ(countDivisible(6, 11, 2), 3);
    ASSERT_EQ(countDivisible(6, 15, 2), 5);
    ASSERT_EQ(countDivisible(7, 15, 4), 2);
    ASSERT_EQ(countDivisible(1, 1, 2), 0);
    ASSERT_EQ(countDivisible(5, 5, 6), 0);
    ASSERT_EQ(countDivisible(1, 5, 6), 0);
    ASSERT_EQ(countDivisible(15, 276, 43), 6);
    ASSERT_EQ(countDivisible(23, 986, 5), 193);
    ASSERT_EQ(countDivisible(48, 3477, 234), 14);
    ASSERT_EQ(countDivisible(27, 276, 12), 21);
    ASSERT_EQ(countDivisible(27, 276, 34), 8);
    ASSERT_EQ(countDivisible(1, 100, 99), 1);
}

class DISABLED_Algorithm_Numeric_Complexity: public testing::Test {};

TEST_F(DISABLED_Algorithm_Numeric_Complexity, countDivisible) {
    countDivisible(0, 2000000000, 2);
    countDivisible(0, 2000000000, 2000000000);
    countDivisible(5, 2000000000, 150000000);
    countDivisible(150000000, 2000000000, 5);
}

}
