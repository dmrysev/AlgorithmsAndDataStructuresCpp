#include "algorithm/find_max_simultaneous_calls.h"

#include <gtest/gtest.h>

using namespace std::chrono_literals;

namespace Algorithm::FindMaxSimultaneousCalls::Test {

TEST(Algorithm_FindMaxSimultaneousCalls, test) {
    auto now = std::chrono::system_clock::now();
    ASSERT_EQ(findMaxSimultaneousCalls({}), 0);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+5s}}), 1);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+5s},{now+6s,now+10s},{now+11s,now+15s}}), 1);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+10s},{now+5s,now+15s},{now+8s,now+12s}}), 3);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+10s},{now+5s,now+8s}}), 2);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+10s},{now+5s,now+15s},{now+12s,now+17s}}), 2);
    ASSERT_EQ(findMaxSimultaneousCalls({{now, now+10s},{now+5s,now+15s},{now+8s,now+12s},{now+14s,now+17s}}), 3);
    ASSERT_EQ(findMaxSimultaneousCalls({
        {now, now+10s},{now+5s,now+15s},{now+8s,now+12s},
        {now+13s,now+17s},{now+15s,now+20s}}), 3);
    ASSERT_EQ(findMaxSimultaneousCalls({
        {now, now+10s},{now+5s,now+20s},
        {now+13s,now+16s},{now+14s,now+25s},{now+16s,now+22s}}), 3);
    ASSERT_EQ(findMaxSimultaneousCalls({
        {now, now+10s},{now+5s,now+15s},
        {now+17s,now+25s},{now+20s,now+28s}}), 2);
    ASSERT_EQ(findMaxSimultaneousCalls({
        {now, now+10s},{now+5s,now+15s},
        {now+17s,now+25s},{now+19s,now+28s},{now+20s,now+22s}}), 3);
}

}
