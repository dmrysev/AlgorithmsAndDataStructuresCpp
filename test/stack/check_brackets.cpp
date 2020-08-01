#include <gtest/gtest.h>

#include "stack/check_brackets.hpp"

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets::Test {

TEST(Stack_CheckBrackets, isClosingsBrackets) {
    ASSERT_TRUE(isClosingsBrackets('{', '}'));
    ASSERT_TRUE(isClosingsBrackets('[', ']'));
    ASSERT_TRUE(isClosingsBrackets('(', ')'));

    ASSERT_FALSE(isClosingsBrackets('}', '{'));
    ASSERT_FALSE(isClosingsBrackets(']', '['));
    ASSERT_FALSE(isClosingsBrackets(')', '('));
    ASSERT_FALSE(isClosingsBrackets('{', ')'));
    ASSERT_FALSE(isClosingsBrackets('{', ']'));
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
