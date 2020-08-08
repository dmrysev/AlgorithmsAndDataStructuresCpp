#include "suffix_array.h"

#include <set>
#include <map>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <stdexcept>

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

// Sliding window implementation
LongestCommonSubstringIndex findLongestCommonSubstringIndex(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    if(strings.size() < 2) return {};
    size_t minStringsCount = minimumStringsCount.value_or(strings.size());
    auto validate = [&] {
        if(minStringsCount < 2 || minStringsCount > strings.size()) {
            throw std::invalid_argument{"Requirements: minimumStringsCount >= 2 && minimumStringsCount <= strings.size()"};
        }
        if(strings.size() > 20) throw std::invalid_argument{"Requirements: strings.size() <= 20"};
        for(const std::string& str: strings) {
            auto it = std::min_element(str.begin(), str.end());
            char minChar = *it;
            if(minChar < 41) {
                std::string msg = "Requirements: For every string in strings "
                    "and for every char in string, char >= 41";
                throw std::invalid_argument{msg};
            }
        }
    };
    validate();
    char sentinel = '#';
    std::string concatString;
    for(const std::string& s: strings) {
        concatString += s + sentinel;
        sentinel++;
    }
    SuffixArray suffixArray = initSuffixArray(concatString);
    LongestCommonPrefixArray lcpa = initLongestCommonPrefixArray(suffixArray, concatString);
    auto getStringIndex = [&] (size_t suffixIndex) {
        size_t length = 0;
        for(size_t i = 0; i < strings.size(); i++) {
            const std::string& str = strings[i];
            length += str.length() + 1;
            if(suffixIndex < length) return i;
        }
        throw std::runtime_error{"String index not found"};
    };
    auto getStringIndexCount = [&] (size_t begin, size_t end) {
        std::map<size_t, size_t> stringIndexCount;
        for(size_t i = 0; i < strings.size(); i++) stringIndexCount[i] = 0;
        for(size_t i = begin; i <= end; i++) {
            size_t suffixIndex = suffixArray[i];
            size_t stringIndex = getStringIndex(suffixIndex);
            stringIndexCount[stringIndex]++;
        }
        return stringIndexCount;
    };
    auto isMinRequiredStringsCountSatisfied = [&] (size_t begin, size_t end) {
        auto stringIndexCount = getStringIndexCount(begin, end);
        size_t stringsCount = 0;
        for(auto& [stringIndex, count]: stringIndexCount) {
            if(count != 0) stringsCount++;
        }
        return stringsCount >= minStringsCount;
    };
    size_t longestCommonSuffixIndex = 0;
    size_t longestCommonSuffixLength = 0;
//    size_t windowEnd = minStringsCount - 1;
    auto suffixes = getSuffixes(concatString, suffixArray);
//    for(auto s: suffixes) {
//        std::cout << s << std::endl;
//    }
    for(size_t i = strings.size(); i < concatString.size(); i++) {
        size_t begin = i;
        size_t end = begin;
        while(!isMinRequiredStringsCountSatisfied(begin, end)) {
            end++;
        }
    }
//    for(size_t i = 0; i < sa.size(); i++) {
//        size_t suffixIndex = sa[i];
//        size_t stringIndex = getStringIndex(suffixIndex);
//    }
    return {};
}

std::string findLongestCommonSubstring(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    auto result = findLongestCommonSubstringIndex(strings, minimumStringsCount);
    size_t from = result.subStringIndex;
    size_t to = from + result.subStringLength;
    return strings.at(result.stringIndex).substr(from, to);
}

}
