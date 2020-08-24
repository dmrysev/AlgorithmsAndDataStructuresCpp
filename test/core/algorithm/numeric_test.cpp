#include "algorithm/numeric.h"
#include <gtest/gtest.h>


namespace Algorithm::Numeric::Test {

TEST(Algorithm_Numeric, findSmallestPositiveMissingInteger) {
    // ARRANGE

    // ACT AND ASSERT
    ASSERT_EQ(findSmallestPositiveMissingInteger({1,3,6,4,1,2}), 5);
    ASSERT_EQ(findSmallestPositiveMissingInteger({1,2,3}), 4);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1,-2}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-2,-1,0}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1,-2,1,3,4}), 2);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,2,3}), 4);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,1,2,2,4}), 3);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0,1,2,3}), 4);
}

}
