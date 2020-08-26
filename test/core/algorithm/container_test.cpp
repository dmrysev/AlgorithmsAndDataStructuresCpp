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

    ASSERT_THROW(findUnpairedValue({}), std::invalid_argument);
    ASSERT_THROW(findUnpairedValue({1, 2}), std::invalid_argument);
}

class DISABLED_Algorithm_Container_Complexity: public testing::Test
{
protected:
    inline static std::vector<int> testVector;

    DISABLED_Algorithm_Container_Complexity() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            const size_t vectorSize = std::pow(10ul, 5ul);
            for(size_t i = 0; i < vectorSize; i++) {
                int value = Util::Numeric::randomNumber<int>(0, 100);
                testVector.push_back(value);
            }
        });
    }
};

TEST_F(DISABLED_Algorithm_Container_Complexity, shiftRight) {
    shiftRight(testVector, testVector.size());
}

}
