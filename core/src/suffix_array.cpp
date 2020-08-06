#include "suffix_array.h"

#include <set>

namespace AlgorithmsAndDataStructures::SuffixArray {

std::vector<size_t> initSuffixArray(const std::string& str) {
    auto compare = [&](size_t a, size_t b) {
        return std::lexicographical_compare(str.begin() + a, str.end(),
                                            str.begin() + b, str.end());
    };
    std::set<size_t, decltype(compare)> suffices(compare);
    for(size_t i = 0; i < str.size(); i++) {
        suffices.insert(i);
    }
    return {suffices.begin(), suffices.end()};
}

std::vector<size_t> initLongestCommonPrefixArray(
    const std::vector<size_t>& suffixArray,
    const std::string& str)
{
    std::vector<size_t> lcpArray(suffixArray.size());
    lcpArray[0] = 0;
    size_t lcpArrayIndex = 1;
    for(auto it = suffixArray.begin(); it < suffixArray.end() - 1; it++) {
        size_t i = 0;
        size_t indexA = *(it);
        size_t indexB = *(it + 1);
        size_t min = std::min(str.size() - indexA, str.size() - indexB);
        while(i < min) {
            char a = str[indexA + i];
            char b = str[indexB + i];
            if(a != b) break;
            i++;
        }
        lcpArray[lcpArrayIndex++] = i;
    }
    return lcpArray;
}

std::vector<size_t> initLongestCommonPrefixArray(const std::string& str) {
    auto suffixArray = initSuffixArray(str);
    return initLongestCommonPrefixArray(suffixArray, str);
}


}
