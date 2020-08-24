#include "algorithm/numeric.h"
#include <set>

namespace Algorithm::Numeric {

int findSmallestPositiveMissingInteger(const std::vector<int>& values) {
    std::set<int> valuesSorted{values.begin(), values.end()};
    int smallest = 1;
    for(int i: valuesSorted) {
        if(i <= 0) continue;
        if(smallest != i) return smallest;
        smallest++;
    }
    return smallest;
}


}
