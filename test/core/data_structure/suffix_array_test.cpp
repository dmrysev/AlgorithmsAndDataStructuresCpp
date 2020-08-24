#include "data_structure/suffix_array.h"
#include "util/string.h"
#include "util/numeric.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mutex>

namespace DataStructure::SuffixArray::Test {

using testing::ElementsAre;

TEST(DataStructure_SuffixArray, initSuffixArray) {
    ASSERT_THAT(initSuffixArray(""), ElementsAre());
    ASSERT_THAT(initSuffixArray("a"), ElementsAre(0));
    ASSERT_THAT(initSuffixArray("ab"), ElementsAre(0, 1));
    ASSERT_THAT(initSuffixArray("abc"), ElementsAre(0, 1, 2));
    ASSERT_THAT(initSuffixArray("abcd"), ElementsAre(0, 1, 2, 3));
    ASSERT_THAT(initSuffixArray("camel"), ElementsAre(1, 0, 3, 4, 2));
    ASSERT_THAT(initSuffixArray("aabaab"), ElementsAre(3,0,4,1,5,2));
    ASSERT_THAT(initSuffixArray("ababbab"), ElementsAre(5, 0, 2, 6, 4, 1, 3));
}

TEST(DataStructure_SuffixArray, initLongestCommonPrefixArray) {
    ASSERT_THAT(initLongestCommonPrefixArray(""), ElementsAre(0));
    ASSERT_THAT(initLongestCommonPrefixArray("camel"), ElementsAre(0,0,0,0,0));
    ASSERT_THAT(initLongestCommonPrefixArray("aabaab"), ElementsAre(0,3,1,2,0,1));
    ASSERT_THAT(initLongestCommonPrefixArray("ababbab"), ElementsAre(0,2,2,0,1,3,1));
}

// COMPLEXITY TESTS

class DISABLED_DataStructure_SuffixArray_Complexity: public testing::Test
{
protected:
    inline static std::string randomString3;
    inline static std::string randomString5;

    DISABLED_DataStructure_SuffixArray_Complexity() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            randomString3 = Util::String::generateRandomString(std::pow(10ul, 3ul));
            randomString5 = Util::String::generateRandomString(std::pow(10ul, 5ul));
        });
    }
};

TEST_F(DISABLED_DataStructure_SuffixArray_Complexity, initSuffixArray) {
    initSuffixArray(randomString5);
}

TEST_F(DISABLED_DataStructure_SuffixArray_Complexity, initLongestCommonPrefixArray) {
    initLongestCommonPrefixArray(randomString5);
}

}
