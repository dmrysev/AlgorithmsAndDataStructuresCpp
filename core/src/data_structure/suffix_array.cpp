#include "data_structure/suffix_array.h"
#include "util/collection.h"

#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace DataStructure::SuffixArray {

SuffixArray initSuffixArray(const std::string& str) {
    auto compare = [&](size_t a, size_t b) {
        return std::lexicographical_compare(str.begin() + a, str.end(),
                                            str.begin() + b, str.end());
    };
    std::set<size_t, decltype(compare)> suffixes(compare);
    for(size_t i = 0; i < str.size(); i++) {
        suffixes.insert(i);
    }
    return {suffixes.begin(), suffixes.end()};
}

std::vector<std::string> getSuffixes(const std::string& str, const SuffixArray& sa) {
    std::vector<std::string> suffixes;
    for(size_t index: sa) {
        suffixes.emplace_back(str.substr(index, str.size()));
    }
    return suffixes;
}

LongestCommonPrefixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str)
{
    if(suffixArray.empty()) return {0};
    LongestCommonPrefixArray lcpArray(suffixArray.size());
    lcpArray[0] = 0;
    size_t lcpArrayIndex = 1;
    for(auto it = suffixArray.begin(); it < suffixArray.end() - 1; it++) {
        size_t i = 0;
        size_t indexA = *(it);
        size_t indexB = *(it + 1);
        while(str[indexA + i] == str[indexB + i]) i++;
        lcpArray[lcpArrayIndex++] = i;
    }
    return lcpArray;
}

LongestCommonPrefixArray initLongestCommonPrefixArray(const std::string& str) {
    auto suffixArray = initSuffixArray(str);
    return initLongestCommonPrefixArray(suffixArray, str);
}
}
