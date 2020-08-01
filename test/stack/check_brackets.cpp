#include <gtest/gtest.h>

#include "stack/check_brackets.hpp"

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets::Test {

TEST(Stack_CheckBrackets, tableTest) {
    ASSERT_TRUE(checkBrackets("[{}]"));
    ASSERT_TRUE(checkBrackets("(()())"));
    ASSERT_TRUE(checkBrackets("[]{}({})"));

    ASSERT_FALSE(checkBrackets("{]"));
    ASSERT_FALSE(checkBrackets("[()]))()"));
}

}
