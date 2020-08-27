#include "algorithm/container.h"
#include "util/numeric.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cmath>
#include <mutex>

using testing::ElementsAre;

namespace Algorithm::Container::Test {

TEST(Algorithm_Container, shiftRight) {
    ASSERT_THAT(shiftRight({}, 1), ElementsAre());
    ASSERT_THAT(shiftRight({1}, 1), ElementsAre(1));
    ASSERT_THAT(shiftRight({3,8,9,7,6}, 1), ElementsAre(6,3,8,9,7));
    ASSERT_THAT(shiftRight({3,8,9,7,6}, 3), ElementsAre(9,7,6,3,8));
    ASSERT_THAT(shiftRight({0,0,0}, 1), ElementsAre(0,0,0));
    ASSERT_THAT(shiftRight({0,0,0}, 2), ElementsAre(0,0,0));
    ASSERT_THAT(shiftRight({0,0,0}, 3), ElementsAre(0,0,0));
    ASSERT_THAT(shiftRight({1,2,3,4}, 4), ElementsAre(1,2,3,4));
    ASSERT_THAT(shiftRight({3,8,9,7,6}, 8), ElementsAre(9,7,6,3,8));
}

TEST(Algorithm_Container, findUnpairedValue) {
    ASSERT_EQ(findUnpairedValue({2}), 2);
    ASSERT_EQ(findUnpairedValue({5,3,5}), 3);
    ASSERT_EQ(findUnpairedValue({9,3,9,3,9,7,9}), 7);
    ASSERT_EQ(findUnpairedValue({1,1,2,2,3}), 3);
    ASSERT_EQ(findUnpairedValue({3,1,1,7,2,2,3}), 7);
}

TEST(Algorithm_Container, findMissingElement) {
    ASSERT_EQ(findMissingElement({}), 1);
    ASSERT_EQ(findMissingElement({1}), 2);
    ASSERT_EQ(findMissingElement({2}), 1);
    ASSERT_EQ(findMissingElement({2,1}), 3);
    ASSERT_EQ(findMissingElement({3,1}), 2);
    ASSERT_EQ(findMissingElement({2,3}), 1);
    ASSERT_EQ(findMissingElement({1,3}), 2);
    ASSERT_EQ(findMissingElement({3,1}), 2);
    ASSERT_EQ(findMissingElement({2,3,1,5}), 4);
}

class DISABLED_Algorithm_Container_Complexity: public testing::Test
{
protected:
    inline static std::vector<int> testVector;
    inline static std::vector<int> testVector2;
    inline static std::vector<int> testVector3;
    inline static int testVector3MissingElement;

    static void SetUpTestCase() {
        const size_t vectorSize = std::pow(10ul, 6ul);
        testVector = std::vector<int>(vectorSize);

        for(size_t i = 0; i < vectorSize; i++) {
            int value = i % (vectorSize / 2);
            testVector2.push_back(value);
        }
        testVector2.push_back(1);

        {
            for(size_t i = 0; i < vectorSize; i++) {
                testVector3.push_back(i);
            }
            testVector3MissingElement = vectorSize / 2;
            testVector3.erase(std::find(testVector3.begin(), testVector3.end(), testVector3MissingElement));
            std::random_shuffle(testVector3.begin(), testVector3.end());
        }
    }
};

TEST_F(DISABLED_Algorithm_Container_Complexity, shiftRight) {
    shiftRight(testVector, testVector.size() / 2);
}

TEST_F(DISABLED_Algorithm_Container_Complexity, findUnpairedValue) {
    ASSERT_EQ(findUnpairedValue(testVector2), 1);
}

TEST_F(DISABLED_Algorithm_Container_Complexity, findMissingElement) {
    int result = findMissingElement(testVector3);
//    ASSERT_EQ(result, testVector3MissingElement);
}

}
