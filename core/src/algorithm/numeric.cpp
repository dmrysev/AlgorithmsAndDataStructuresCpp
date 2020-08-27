#include "algorithm/numeric.h"
#include "data_structure/prefix_sum.h"
#include <set>
#include <bitset>
#include <algorithm>

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

int findLargestBinaryGap(int n) {
    constexpr size_t bits = std::numeric_limits<int>::digits + 1;
    auto bitset = std::bitset<bits>(n);
    std::set<int> gapSizes;
    int currentGapSize = 0;
    bool isGapBegin = false;
    for(size_t i = 0; i < bitset.size(); i++) {
        bool bitValue = bitset.test(i);
        if(bitValue == true && currentGapSize == 0) {
            isGapBegin = true;
        }
        else if(bitValue == true && currentGapSize > 0) {
            gapSizes.insert(currentGapSize);
            currentGapSize = 0;
        }
        else if(bitValue == false && isGapBegin) {
            currentGapSize++;
        }
    }
    auto largestGapSize = std::max_element(gapSizes.begin(), gapSizes.end());
    return *largestGapSize;
}

int countDivisible(int from, int to, int divisor) {
//    auto prefixSum = DataStructure::PrefixSum::initPrefixSum()
    return 0;
}


}
