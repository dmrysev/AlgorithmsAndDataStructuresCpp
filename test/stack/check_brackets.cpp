#include <gtest/gtest.h>

#include "stack/check_brackets.hpp"

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets::Test {

TEST(Stack_CheckBrackets, isClosingBracket) {
    ASSERT_TRUE(isClosingBracket('{', '}'));
    ASSERT_TRUE(isClosingBracket('[', ']'));
    ASSERT_TRUE(isClosingBracket('(', ')'));

    ASSERT_FALSE(isClosingBracket('}', '{'));
    ASSERT_FALSE(isClosingBracket(']', '['));
    ASSERT_FALSE(isClosingBracket(')', '('));
    ASSERT_FALSE(isClosingBracket('{', ')'));
    ASSERT_FALSE(isClosingBracket('{', ']'));
}

TEST(Stack_CheckBrackets, checkBrackets) {
    ASSERT_TRUE(checkBrackets(""));
    ASSERT_TRUE(checkBrackets("[{}]"));
    ASSERT_TRUE(checkBrackets("(()())"));
    ASSERT_TRUE(checkBrackets("[]{}({})"));

    ASSERT_FALSE(checkBrackets("{]"));
    ASSERT_FALSE(checkBrackets("[()]))()"));
}

}
