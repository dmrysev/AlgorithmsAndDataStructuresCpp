#include "suffix_array.h"

#include <set>
#include <numeric>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

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
    std::vector<std::string> suffixes(str.size());
    for(size_t index: sa) {
        suffixes.emplace_back(str.substr(index, str.size()));
    }
    return suffixes;
}

LongestCommonSuffixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str)
{
    if(suffixArray.empty()) return {0};
    LongestCommonSuffixArray lcpArray(suffixArray.size());
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

LongestCommonSuffixArray initLongestCommonPrefixArray(const std::string& str) {
    auto suffixArray = initSuffixArray(str);
    return initLongestCommonPrefixArray(suffixArray, str);
}

size_t findSubstringsCount(const std::string& str) {
    size_t n = str.size();
    return n * (n + 1) / 2;
}

size_t findRepeatedSubstringsCount(const std::string& str) {
    auto lcpArray = initLongestCommonPrefixArray(str);
    return std::accumulate(lcpArray.begin(), lcpArray.end(), 0);
}

size_t findUniqueSubstringsCount(const std::string& str) {
    size_t substringsCount = findSubstringsCount(str);
    size_t repeatedSubstringsCount = findRepeatedSubstringsCount(str);
    return substringsCount - repeatedSubstringsCount;
}

}
