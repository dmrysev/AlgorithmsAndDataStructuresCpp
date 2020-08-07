#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "suffix_array.h"

namespace AlgorithmsAndDataStructures::SuffixArray::Test {

using testing::ElementsAre;

TEST(SuffixArray, initSuffixArray) {
    ASSERT_THAT(initSuffixArray(""), ElementsAre());
    ASSERT_THAT(initSuffixArray("a"), ElementsAre(0));
    ASSERT_THAT(initSuffixArray("ab"), ElementsAre(0, 1));
    ASSERT_THAT(initSuffixArray("abc"), ElementsAre(0, 1, 2));
    ASSERT_THAT(initSuffixArray("abcd"), ElementsAre(0, 1, 2, 3));
    ASSERT_THAT(initSuffixArray("camel"), ElementsAre(1, 0, 3, 4, 2));
    ASSERT_THAT(initSuffixArray("ababbab"), ElementsAre(5, 0, 2, 6, 4, 1, 3));
}

TEST(SuffixArray, initLongestCommonPrefixArray) {
    ASSERT_THAT(initLongestCommonPrefixArray(""), ElementsAre(0));
    ASSERT_THAT(initLongestCommonPrefixArray("camel"), ElementsAre(0,0,0,0,0));
    ASSERT_THAT(initLongestCommonPrefixArray("ababbab"), ElementsAre(0,2,2,0,1,3,1));
}

TEST(SuffixArray, findUniqueSubstringsCount) {
    ASSERT_EQ(findUniqueSubstringsCount(""), 0);
    ASSERT_EQ(findUniqueSubstringsCount("aaa"), 3);
    ASSERT_EQ(findUniqueSubstringsCount("abab"), 7);
    ASSERT_EQ(findUniqueSubstringsCount("azaza"), 9);
}

}
