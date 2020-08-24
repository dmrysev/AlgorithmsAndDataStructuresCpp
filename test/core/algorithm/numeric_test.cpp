#include "algorithm/numeric.h"
#include <gtest/gtest.h>


namespace Algorithm::Numeric::Test {

TEST(Algorithm_Numeric, findSmallestPositiveMissingInteger) {
    ASSERT_EQ(findSmallestPositiveMissingInteger({1, 3, 6, 4, 1, 2}), 5);
    ASSERT_EQ(findSmallestPositiveMissingInteger({1, 2, 3}), 4);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1, -2}), 1);
    ASSERT_EQ(findSmallestPositiveMissingInteger({-1, -2, 1}), 2);
    ASSERT_EQ(findSmallestPositiveMissingInteger({0, 1, 2, 3}), 4);
}

}
