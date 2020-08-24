#include "algorithm/longest_common_sub_string.h"
#include "util/string.h"
#include "util/numeric.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mutex>

namespace Algorithm::LongestCommonSubString::Test {

using testing::ElementsAre;

std::string findLongestCommonSubstringAdapter(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {})
{
    auto stringOption = findLongestCommonSubstring(strings, minimumStringsCount);
    if(stringOption) return stringOption.value();
    return "";
}

TEST(Algorithm_LongestCommonSubString, findLongestCommonSubstring) {
    ASSERT_EQ(findLongestCommonSubstring({"ab", "cd"}), std::nullopt);
    ASSERT_EQ(findLongestCommonSubstring({"a", "b", "c"}), std::nullopt);

    ASSERT_EQ(findLongestCommonSubstringAdapter({"ab", "ac", "ad"}), "a");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abc", "abc", "add"}), "a");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"ab", "ab", "ab"}), "ab");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"aaa", "aaa", "aaa"}), "aaa");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abca", "bcad", "daca"}), "ca");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"aabaa", "aadaa", "aacaa"}), "aa");

    ASSERT_EQ(findLongestCommonSubstringAdapter({"zxybca", "zxybcd", "zxybcc"}), "zxybc");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"zxybca", "zxybcd", "zxybcc"}, 2), "zxybc");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abzxybca", "adzxybcd", "aczxybcc"}), "zxybc");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abzxybca", "adzxybcc", "aczxybcc"}, 2), "zxybcc");

    ASSERT_EQ(findLongestCommonSubstringAdapter({"bcabc", "bdaaaabd", "beabe", "bfabababf"}), "ab");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"baaab", "caaaac", "daaaaad"}), "aaa");

    ASSERT_EQ(findLongestCommonSubstringAdapter({"abca", "bcad", "daca"}, 2), "bca");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abca", "bcad", "daca"}, 3), "ca");
    ASSERT_EQ(findLongestCommonSubstringAdapter({"abcaab", "bcaad", "daca"}, 2), "bcaa");

    ASSERT_THROW(findLongestCommonSubstringAdapter({}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({""}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({"", ""}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({"abc"}), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({"abc", "abc", "abc"}, 0), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({"abc", "abc", "abc"}, 1), std::invalid_argument);
    ASSERT_THROW(findLongestCommonSubstringAdapter({"abc", "abc", "abc"}, 4), std::invalid_argument);
}

TEST(Algorithm_LongestCommonSubString, findLongestCommonUniqueSubstrings) {
    ASSERT_THAT(findLongestCommonUniqueSubstrings({"aaZbb", "aaXbb", "aaYbb"}), ElementsAre("aa", "bb"));
    ASSERT_THAT(findLongestCommonUniqueSubstrings({"aaaZbbZcc", "aaXbbbXcc", "aaYbbYccc"}), ElementsAre("aa", "bb", "cc"));
    ASSERT_THAT(findLongestCommonUniqueSubstrings({"aaabbb", "bbbaaa"}), ElementsAre("aaa", "bbb"));
}

TEST(Algorithm_LongestCommonSubString, findLongestCommonSubstring_random) {
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

class DISABLED_Algorithms_LongestCommonSubString_Complexity: public testing::Test
{
protected:
    inline static std::string randomString3;
    inline static std::string randomString5;

    DISABLED_Algorithms_LongestCommonSubString_Complexity() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            randomString3 = Util::String::generateRandomString(std::pow(10ul, 3ul));
            randomString5 = Util::String::generateRandomString(std::pow(10ul, 5ul));
        });
    }
};

TEST_F(DISABLED_Algorithms_LongestCommonSubString_Complexity, findLongestCommonSubstring) {
    ASSERT_EQ(findLongestCommonSubstringAdapter({randomString3, randomString3}), randomString3);
}

}
