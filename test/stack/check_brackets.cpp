#include <gtest/gtest.h>

#include "stack/check_brackets.hpp"

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets::Test {

TEST(Stack_CheckBrackets, isReversedBracket) {
    ASSERT_TRUE(isReversedBracket('{', '}'));
    ASSERT_TRUE(isReversedBracket('[', ']'));
    ASSERT_TRUE(isReversedBracket('(', ')'));

    ASSERT_FALSE(isReversedBracket('}', '{'));
    ASSERT_FALSE(isReversedBracket(']', '['));
    ASSERT_FALSE(isReversedBracket(')', '('));
    ASSERT_FALSE(isReversedBracket('{', ')'));
    ASSERT_FALSE(isReversedBracket('{', ']'));
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
