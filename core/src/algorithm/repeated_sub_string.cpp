#include "algorithm/repeated_sub_string.h"
#include "data_structure/suffix_array.h"
#include "util/collection.h"

#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace DataStructure::SuffixArray;

namespace Algorithm::RepeatedSubString {

size_t findSubstringsCount(const std::string& str) {
    size_t n = str.size();
    return n * (n + 1) / 2;
}

size_t findRepeatedSubstringsCount(const std::string& str) {
    auto lcpArray = initLongestCommonPrefixArray(str);
    return std::accumulate(lcpArray.begin(), lcpArray.end(), 0);
}

size_t findUniqueRepeatedSubstringsCount(const std::string& str) {
    LongestCommonPrefixArray lcpa = initLongestCommonPrefixArray(str);
    size_t sum = 0;
    for(size_t i = 1; i < lcpa.size(); i++) {
        size_t prev = lcpa[i - 1];
        size_t curr = lcpa[i];
        if(prev < curr) {
            sum += (curr - prev);
        }
        else if(curr > prev) sum += curr;

    }
    return sum;
}

size_t findUniqueSubstringsCount(const std::string& str) {
    size_t substringsCount = findSubstringsCount(str);
    size_t repeatedSubstringsCount = findRepeatedSubstringsCount(str);
    return substringsCount - repeatedSubstringsCount;
}

}
