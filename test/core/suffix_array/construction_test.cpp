#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "suffix_array/construction.h"

namespace AlgorithmsAndDataStructures::Core::SuffixArray::Construction::Test {

using testing::ElementsAre;

TEST(SuffixArray_Construction, naiveApproach) {
    ASSERT_THAT(initSuffixArray(""), ElementsAre());
    ASSERT_THAT(initSuffixArray("a"), ElementsAre(0));
    ASSERT_THAT(initSuffixArray("ab"), ElementsAre(0, 1));
    ASSERT_THAT(initSuffixArray("abc"), ElementsAre(0, 1, 2));
    ASSERT_THAT(initSuffixArray("abcd"), ElementsAre(0, 1, 2, 3));
    ASSERT_THAT(initSuffixArray("camel"), ElementsAre(1, 0, 3, 4, 2));
    ASSERT_THAT(initSuffixArray("ababbab"), ElementsAre(5, 0, 2, 6, 4, 1, 3));
}

}
