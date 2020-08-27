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
    ASSERT_EQ(findMissingElement({3,4,2}), 1);
    ASSERT_EQ(findMissingElement({3,1,2}), 4);
    ASSERT_EQ(findMissingElement({2,3,1,5}), 4);
    ASSERT_EQ(findMissingElement({4,5,6,2}), 1);
    ASSERT_EQ(findMissingElement({2,1,1}), 3);
    ASSERT_EQ(findMissingElement({1,1,2,2}), 3);
    ASSERT_EQ(findMissingElement({1,1,3,3}), 2);
    ASSERT_EQ(findMissingElement({1,2,4,9}), 3);
    ASSERT_EQ(findMissingElement({1,2,3,9}), 4);
    std::vector<int> i1;
    i1.push_back(-1);
    i1.push_back(-3);
    ASSERT_EQ(findMissingElement(i1), 1);
}

TEST(Algorithm_Container, tapeEquilibrium) {
    ASSERT_EQ(tapeEquilibrium({1,1}), 0);
    ASSERT_EQ(tapeEquilibrium({1,1}), 0);
    ASSERT_EQ(tapeEquilibrium({1,2}), 1);
    ASSERT_EQ(tapeEquilibrium({-4,1,8}), 11);
    ASSERT_EQ(tapeEquilibrium({6,3}), 3);
    ASSERT_EQ(tapeEquilibrium({1,4,9}), 4);
    ASSERT_EQ(tapeEquilibrium({3,1,2,4,3}), 1);
}

TEST(Algorithm_Container, findEarliestAvailablePath) {
    ASSERT_EQ(findEarliestAvailablePath({1}, 1), 0);
    ASSERT_EQ(findEarliestAvailablePath({1,2}, 2), 1);
    ASSERT_EQ(findEarliestAvailablePath({1,2,3,4}, 2), 1);
    ASSERT_EQ(findEarliestAvailablePath({3,2,1,4}, 4), 3);
    ASSERT_EQ(findEarliestAvailablePath({4,2,1,3}, 4), 3);
    ASSERT_EQ(findEarliestAvailablePath({2,4,3,1}, 4), 3);
    ASSERT_EQ(findEarliestAvailablePath({2,4,3,1,4}, 4), 3);
    ASSERT_EQ(findEarliestAvailablePath({2,4,3,1,5}, 4), 3);
    ASSERT_EQ(findEarliestAvailablePath({3,3,3,3,2,1}, 3), 5);
    ASSERT_EQ(findEarliestAvailablePath({2,3,1,2,2,4,6,5}, 4), 5);
    ASSERT_EQ(findEarliestAvailablePath({1,3,1,4,2,3,5,4}, 5), 6);
    ASSERT_EQ(findEarliestAvailablePath({1,5,1,4,2,3,3,4}, 5), 5);

//    ASSERT_EQ(findEarliestAvailablePath({1}, 2), -1);
    ASSERT_EQ(findEarliestAvailablePath({2,3,1}, 4), -1);
    ASSERT_EQ(findEarliestAvailablePath({2,5,1}, 3), -1);
    ASSERT_EQ(findEarliestAvailablePath({4,5,3}, 1), -1);
}

class DISABLED_Algorithm_Container_Complexity: public testing::Test
{
protected:
    inline static std::vector<int> testVector;
    inline static std::vector<int> testVector2;
    inline static std::vector<int> testVector3;
    inline static std::vector<int> testVector4;
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

        testVector4.reserve(vectorSize);
        for(size_t i = 1; i < vectorSize; i++) {
            testVector4.push_back(i);
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
    findMissingElement(testVector3);
}

TEST_F(DISABLED_Algorithm_Container_Complexity, tapeEquilibrium) {
    tapeEquilibrium(testVector2);
}

TEST_F(DISABLED_Algorithm_Container_Complexity, findEarliestAvailablePath) {
    ASSERT_EQ(findEarliestAvailablePath(testVector4, testVector4.size()), testVector4.size() - 1);
}

}
