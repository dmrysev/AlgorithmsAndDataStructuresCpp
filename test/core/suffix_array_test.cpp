#include "suffix_array.h"
#include "util/string.h"
#include "util/numeric.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mutex>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms::Test {

using testing::ElementsAre;

TEST(SuffixArrayAlgorithms, initSuffixArray) {
    ASSERT_THAT(initSuffixArray(""), ElementsAre());
    ASSERT_THAT(initSuffixArray("a"), ElementsAre(0));
    ASSERT_THAT(initSuffixArray("ab"), ElementsAre(0, 1));
    ASSERT_THAT(initSuffixArray("abc"), ElementsAre(0, 1, 2));
    ASSERT_THAT(initSuffixArray("abcd"), ElementsAre(0, 1, 2, 3));
    ASSERT_THAT(initSuffixArray("camel"), ElementsAre(1, 0, 3, 4, 2));
    ASSERT_THAT(initSuffixArray("aabaab"), ElementsAre(3,0,4,1,5,2));
    ASSERT_THAT(initSuffixArray("ababbab"), ElementsAre(5, 0, 2, 6, 4, 1, 3));
}

TEST(SuffixArrayAlgorithms, initLongestCommonPrefixArray) {
    ASSERT_THAT(initLongestCommonPrefixArray(""), ElementsAre(0));
    ASSERT_THAT(initLongestCommonPrefixArray("camel"), ElementsAre(0,0,0,0,0));
    ASSERT_THAT(initLongestCommonPrefixArray("aabaab"), ElementsAre(0,3,1,2,0,1));
    ASSERT_THAT(initLongestCommonPrefixArray("ababbab"), ElementsAre(0,2,2,0,1,3,1));
}

TEST(SuffixArrayAlgorithms, findRepeatedSubstringsCount) {
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

TEST(SuffixArrayAlgorithms, findUniqueRepeatedSubstringsCount) {
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

TEST(SuffixArrayAlgorithms, findUniqueSubstringsCount) {
    ASSERT_EQ(findUniqueSubstringsCount(""), 0);
    ASSERT_EQ(findUniqueSubstringsCount("a"), 1);
    ASSERT_EQ(findUniqueSubstringsCount("aa"), 2);
    ASSERT_EQ(findUniqueSubstringsCount("ab"), 3);
    ASSERT_EQ(findUniqueSubstringsCount("aaa"), 3);
    ASSERT_EQ(findUniqueSubstringsCount("abab"), 7);
    ASSERT_EQ(findUniqueSubstringsCount("azaza"), 9);
    ASSERT_EQ(findUniqueSubstringsCount("aabaab"), 14);
}

TEST(SuffixArrayAlgorithms, findLongestCommonSubstring) {
    ASSERT_EQ(findLongestCommonSubstring({"ab", "cd"}), std::nullopt);
    ASSERT_EQ(findLongestCommonSubstring({"a", "b", "c"}), std::nullopt);
    ASSERT_EQ(findLongestCommonSubstring({"ab", "ac", "ad"}), "a");
    ASSERT_EQ(findLongestCommonSubstring({"abc", "abc", "add"}), "a");
    ASSERT_EQ(findLongestCommonSubstring({"ab", "ab", "ab"}), "ab");
    ASSERT_EQ(findLongestCommonSubstring({"aaa", "aaa", "aaa"}), "aaa");
    ASSERT_EQ(findLongestCommonSubstring({"abca", "bcad", "daca"}), "ca");
    ASSERT_EQ(findLongestCommonSubstring({"aabaa", "aadaa", "aacaa"}), "aa");

    ASSERT_EQ(findLongestCommonSubstring({"zxybca", "zxybcd", "zxybcc"}), "zxybc");
    ASSERT_EQ(findLongestCommonSubstring({"zxybca", "zxybcd", "zxybcc"}, 2), "zxybc");
    ASSERT_EQ(findLongestCommonSubstring({"abzxybca", "adzxybcd", "aczxybcc"}), "zxybc");
    ASSERT_EQ(findLongestCommonSubstring({"abzxybca", "adzxybcc", "aczxybcc"}, 2), "zxybcc");

    ASSERT_EQ(findLongestCommonSubstring({"bcabc", "bdaaaabd", "beabe", "bfabababf"}), "ab");
    ASSERT_EQ(findLongestCommonSubstring({"baaab", "caaaac", "daaaaad"}), "aaa");

    ASSERT_EQ(findLongestCommonSubstring({"abca", "bcad", "daca"}, 2), "bca");
    ASSERT_EQ(findLongestCommonSubstring({"abca", "bcad", "daca"}, 3), "ca");
    ASSERT_EQ(findLongestCommonSubstring({"abcaab", "bcaad", "daca"}, 2), "bcaa");

    ASSERT_THROW(findLongestCommonSubstring({}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({""}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({"", ""}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({"abc"}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({"abc", "abc", "abc"}, 0), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({"abc", "abc", "abc"}, 1), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstring({"abc", "abc", "abc"}, 4), std::invalid_argument);
}

TEST(SuffixArrayAlgorithms, findLongestCommonSubstrings) {
//    ASSERT_THAT(findLongestCommonSubstrings({"aaZbb", "aaXbb", "aaYbb"}), ElementsAre("aa", "bb"));
}

TEST(SuffixArrayAlgorithms, findLongestCommonSubstring_random) {
    // ARRANGE
    const size_t commonSubstringSize = Util::Numeric::randomNumber(2, 30);
    const int maximumStringsCount = 10;
    const char startChar = 'A';
    const char endChar = 'z';
    auto commonSubstring = Util::String::generateRandomString(commonSubstringSize, startChar + maximumStringsCount, endChar);
    char uniqueDelimeter = 'A';
    auto generateString = [&] {
        int maximumSize = static_cast<int>(commonSubstringSize - 1);
        int prefixSize = Util::Numeric::randomNumber(0, maximumSize);
        auto randomPrefix = Util::String::generateRandomString(prefixSize, startChar, endChar);
        int suffixSize = Util::Numeric::randomNumber(0, maximumSize);
        auto randomSuffix = Util::String::generateRandomString(suffixSize, startChar, endChar);
        auto result = randomPrefix + uniqueDelimeter + commonSubstring + uniqueDelimeter + randomSuffix;
        uniqueDelimeter++;
        return result;
    };
    std::vector<std::string> strings;
    int stringsCount = Util::Numeric::randomNumber(2, maximumStringsCount);
    for(int i = 0; i < stringsCount; i++) strings.push_back(generateString());
    auto minRequiredStringsCount = Util::Numeric::randomNumber<size_t>(2, stringsCount);

    // ACT
    auto result = findLongestCommonSubstring(strings, minRequiredStringsCount);

    // ASSERT
    ASSERT_EQ(result, commonSubstring);
}

// COMPLEXITY TESTS

class DISABLED_SuffixArray_Complexity: public testing::Test
{
protected:
    inline static std::string randomString3;
    inline static std::string randomString5;

    DISABLED_SuffixArray_Complexity() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            randomString3 = Util::String::generateRandomString(std::pow(10ul, 3ul));
            randomString5 = Util::String::generateRandomString(std::pow(10ul, 5ul));
        });
    }
};

TEST_F(DISABLED_SuffixArray_Complexity, initSuffixArray) {
    initSuffixArray(randomString5);
}

TEST_F(DISABLED_SuffixArray_Complexity, initLongestCommonPrefixArray) {
    initLongestCommonPrefixArray(randomString5);
}

TEST_F(DISABLED_SuffixArray_Complexity, findUniqueSubstringsCount) {
    findUniqueSubstringsCount(randomString5);
}

TEST_F(DISABLED_SuffixArray_Complexity, findUniqueRepeatedSubstringsCount) {
    findUniqueSubstringsCount(randomString5);
}

TEST_F(DISABLED_SuffixArray_Complexity, findLongestCommonSubstring) {
    ASSERT_EQ(findLongestCommonSubstring({randomString3, randomString3}), randomString3);
}

}
