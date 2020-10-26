#pragma once

#include <chrono>
#include <vector>
#include <algorithm>

namespace Algorithm::FindMaxSimultaneousCalls {

struct DateTimeRange {
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point finish;
};

struct Call {
    DateTimeRange dateTimeRange;
};

int findMaxSimultaneousCalls(const std::vector<Call>& calls);

}
