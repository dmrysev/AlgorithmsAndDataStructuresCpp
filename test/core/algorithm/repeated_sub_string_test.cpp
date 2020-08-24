#include "algorithm/repeated_sub_string.h"
#include "util/string.h"
#include "util/numeric.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mutex>

namespace Algorithm::RepeatedSubString::Test {

using testing::ElementsAre;

TEST(Algorithm_RepeatedSubString, findRepeatedSubstringsCount) {
    ASSERT_EQ(findRepeatedSubstringsCount("a"), 0);
    ASSERT_EQ(findRepeatedSubstringsCount("ab"), 0);
    ASSERT_EQ(findRepeatedSubstringsCount("aa"), 1);
    ASSERT_EQ(findRepeatedSubstringsCount("aab"), 1);
    ASSERT_EQ(findRepeatedSubstringsCount("abab"), 3);
    ASSERT_EQ(findRepeatedSubstringsCount("aaa"), 3);
    ASSERT_EQ(findRepeatedSubstringsCount("abac"), 1);
    ASSERT_EQ(findRepeatedSubstringsCount("abaca"), 2);
    ASSERT_EQ(findRepeatedSubstringsCount("aabcd"), 1);
    ASSERT_EQ(findRepeatedSubstringsCount("abcabc"), 6);
    ASSERT_EQ(findRepeatedSubstringsCount("aabaab"), 7);
}

TEST(Algorithm_RepeatedSubString, findUniqueRepeatedSubstringsCount) {
    ASSERT_EQ(findUniqueRepeatedSubstringsCount(""), 0);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aa"), 1);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aaa"), 2);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aaaa"), 3);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aaaaa"), 4);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("ab"), 0);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aba"), 1);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("abaa"), 1);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("abaaa"), 2);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("abab"), 3);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("abcabc"), 6);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("aabaab"), 5);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("baabaa"), 5);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("AaAaA"), 5);
    ASSERT_EQ(findUniqueRepeatedSubstringsCount("azaza"), 5);
}

TEST(Algorithm_RepeatedSubString, findUniqueSubstringsCount) {
    ASSERT_EQ(findUniqueSubstringsCount(""), 0);
    ASSERT_EQ(findUniqueSubstringsCount("a"), 1);
    ASSERT_EQ(findUniqueSubstringsCount("aa"), 2);
    ASSERT_EQ(findUniqueSubstringsCount("ab"), 3);
    ASSERT_EQ(findUniqueSubstringsCount("aaa"), 3);
    ASSERT_EQ(findUniqueSubstringsCount("abab"), 7);
    ASSERT_EQ(findUniqueSubstringsCount("azaza"), 9);
    ASSERT_EQ(findUniqueSubstringsCount("aabaab"), 14);
}

// COMPLEXITY TESTS

class DISABLED_Algorithm_RepeatedSubString_Complexity: public testing::Test
{
protected:
    inline static std::string randomString3;
    inline static std::string randomString5;

    DISABLED_Algorithm_RepeatedSubString_Complexity() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            randomString3 = Util::String::generateRandomString(std::pow(10ul, 3ul));
            randomString5 = Util::String::generateRandomString(std::pow(10ul, 5ul));
        });
    }
};

TEST_F(DISABLED_Algorithm_RepeatedSubString_Complexity, findUniqueSubstringsCount) {
    findUniqueSubstringsCount(randomString5);
}

TEST_F(DISABLED_Algorithm_RepeatedSubString_Complexity, findUniqueRepeatedSubstringsCount) {
    findUniqueSubstringsCount(randomString5);
}

}
