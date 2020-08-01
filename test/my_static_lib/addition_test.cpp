#include "my_static_lib/addition.hpp"

#include <gtest/gtest.h>

namespace AlgorithmsAndDataStructures::Test {

using namespace MyStaticLib;

TEST(MyStaticLibr, givenNumber_callingAdd2_mustReturnNumberIncreasedBy2) {
    // ARRANGE
    double input1 = 10.5;
    double input2 = 12.3;

    // ACT
    double result1 = Addition::add2(input1);
    double result2 = Addition::add2(input2);

    // ASSERT
    ASSERT_EQ(result1, 12.5);
    ASSERT_EQ(result2, 14.3);
}

}