#include "my_dynamic_lib/multiplication.hpp"

#include <gtest/gtest.h>

namespace AlgorithmsAndDataStructures::Test {

using namespace MyDynamicLib;

TEST(MyDynamicLib, givenNumber_callingMultBy2_mustReturnNumberMultipliedBy2) {
    // ARRANGE
    double input1 = 10.5;
    double input2 = 12.3;

    // ACT
    double result1 = Multiplication::multBy2(input1);
    double result2 = Multiplication::multBy2(input2);

    // ASSERT
    ASSERT_EQ(result1, 21);
    ASSERT_EQ(result2, 24.6);
}

}