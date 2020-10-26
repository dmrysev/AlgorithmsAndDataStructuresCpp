#include "algorithm/find_max_simultaneous_calls.h"
#include <algorithm>

namespace Algorithm::FindMaxSimultaneousCalls {

namespace  {

bool hasOverlap(const DateTimeRange& range1, const DateTimeRange& range2) {
    if(range1.start <= range2.start && range2.start <= range1.finish) return true;
    return false;
}

}

int findMaxSimultaneousCalls(const std::vector<Call>& calls) {
    if(calls.empty()) return 0;
    if(calls.size() == 1) return 1;
    int maxSimultaneousCalls = 1;
    int currentSimultaneousCalls = 1;
    int currentOverlapIndex = 0;
    for(int i = 1; i < calls.size(); i++) {
        if(hasOverlap(calls[currentOverlapIndex].dateTimeRange, calls[i].dateTimeRange)) {
            if(++currentSimultaneousCalls > maxSimultaneousCalls) {
                maxSimultaneousCalls = currentSimultaneousCalls;
            }
        }
        else {
            currentSimultaneousCalls = 1;
            currentOverlapIndex = i;
        }
    }
    return maxSimultaneousCalls;
}


}
