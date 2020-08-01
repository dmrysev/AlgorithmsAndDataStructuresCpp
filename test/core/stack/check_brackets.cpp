#include <gtest/gtest.h>

#include "stack/check_brackets.h"

namespace AlgorithmsAndDataStructures::Core::Stack::CheckBrackets::Test {

TEST(Stack_CheckBrackets, checkBrackets) {
    ASSERT_TRUE(checkBrackets(""));
    ASSERT_TRUE(checkBrackets("[{}]"));
    ASSERT_TRUE(checkBrackets("(()())"));
    ASSERT_TRUE(checkBrackets("[]{}({})"));
    ASSERT_TRUE(checkBrackets("[[{}]()]"));

    ASSERT_FALSE(checkBrackets("{]"));
    ASSERT_FALSE(checkBrackets("[()]))()"));
}

}
