#include "algorithm/container.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::ElementsAre;

namespace Algorithm::Container::Test {

TEST(Algorithm_Container, shiftRight) {
    ASSERT_THAT(shiftRight({3,8,9,7,6}, 3), ElementsAre(9,7,6,3,8));
    ASSERT_THAT(shiftRight({0,0,0}, 3), ElementsAre(0,0,0));
    ASSERT_THAT(shiftRight({1,2,3,4}, 4), ElementsAre(1,2,3,4));
}

}
