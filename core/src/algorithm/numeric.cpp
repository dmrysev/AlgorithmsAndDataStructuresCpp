#include "algorithm/numeric.h"
#include "data_structure/prefix_sum.h"
#include <set>
#include <bitset>
#include <algorithm>
#include <stdexcept>

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

namespace CountDivisibleImpl {

int naive(int from, int to, int divisor) {
    int count = 0;
    for(int i = from; i <= to; i++) {
        if(i % divisor == 0) count++;
    }
    return count;
}

int fast(int from, int to, int divisor) {
    if(divisor > to) {
        if(from == 0) return 1;
        return 0;
    }
    int firstDivisable = [&] {
        if(from == 0) return from;
        if(divisor >= from) return divisor;
        for(int i = from; i <= to; i++) {
            if(i % divisor == 0) return i;
        }
        return -1;
    }();
    if(firstDivisable == -1) return 0;
    int diff = to - firstDivisable;
    int rem = diff % divisor;
    int result = (diff - rem) / divisor + 1;
    return result;
}

}

int countDivisible(int from, int to, int divisor) {
    return CountDivisibleImpl::fast(from, to, divisor);
}

}
