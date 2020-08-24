#include "algorithm/string_validation.h"

#include <gtest/gtest.h>

namespace Algorithm::StringValidation::Test {

TEST(Algorithm_StringValidation, checkBrackets) {
    ASSERT_TRUE(checkBrackets(""));
    ASSERT_TRUE(checkBrackets("[{}]"));
    ASSERT_TRUE(checkBrackets("(()())"));
    ASSERT_TRUE(checkBrackets("[]{}({})"));
    ASSERT_TRUE(checkBrackets("[[{}]()]"));

    ASSERT_FALSE(checkBrackets("{]"));
    ASSERT_FALSE(checkBrackets("[()]))()"));
}

}
