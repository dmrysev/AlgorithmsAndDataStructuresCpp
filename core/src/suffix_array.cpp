#include "suffix_array.h"

#include <set>
#include <map>
#include <numeric>
#include <sstream>
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
std::vector<LongestCommonSubstringIndex> findLongestCommonSubstringIndexes(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    const char startingChar = 'A';
    size_t minStringsCount = minimumStringsCount.value_or(strings.size());
    auto validate = [&] {
        if(strings.size() < 2) throw std::invalid_argument{"Requirement: strings.size() >= 2"};
        if(minStringsCount < 2 || minStringsCount > strings.size()) {
            throw std::invalid_argument{"Requirements: minimumStringsCount >= 2 && minimumStringsCount <= strings.size()"};
        }
        if(strings.size() > 20) throw std::invalid_argument{"Requirements: strings.size() <= 20"};
        for(const std::string& str: strings) {
            auto it = std::min_element(str.begin(), str.end());
            char minChar = *it;
            if(minChar < startingChar) {
                std::stringstream ss;
                ss << "Requirements: For every string in strings "
                   << "and for every char in string, char >= " << (int) startingChar;
                throw std::invalid_argument{ss.str()};
            }
        }
    };
    validate();
    char sentinel = '!';
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
    auto getStringIndexesCounts = [&] (size_t begin, size_t end) {
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
        auto stringIndexesCounts = getStringIndexesCounts(begin, end);
        size_t stringsCount = 0;
        for(auto& [stringIndex, count]: stringIndexesCounts) {
            if(count != 0) stringsCount++;
        }
        return stringsCount >= minStringsCount;
    };
    auto hasCommonPrefix = [&](size_t begin, size_t end) {
        for(size_t i = begin + 1; i <= end; i++) {
            if(lcpa[i] == 0) return false;
        }
        return true;
    };
    #ifndef NDEBUG
    auto suffixes = getSuffixes(concatString, suffixArray);
    #endif
    std::vector<LongestCommonSubstringIndex> lcsIndexes;
    for(size_t begin = strings.size(), end = begin + minStringsCount - 1; ;) {
        while(!isMinRequiredStringsCountSatisfied(begin, end) && end + 1 < lcpa.size()) end++;
        while(!hasCommonPrefix(begin, end)) begin++;
        if(!isMinRequiredStringsCountSatisfied(begin, end)) {
            if(end == lcpa.size() - 1) break;
            else continue;
        }
        size_t lcpIndexForWindow = end;
        size_t currentLcsLength = lcsIndexes.empty() ? 0 : lcsIndexes[0].subStringLength;
        if(lcpa[lcpIndexForWindow] >= currentLcsLength) {
            LongestCommonSubstringIndex lcsi;
            size_t suffixIndex = suffixArray[lcpIndexForWindow];
            lcsi.stringIndex = getStringIndex(suffixIndex);
            lcsi.subStringLength = lcpa[lcpIndexForWindow];
            const std::string& str = strings.at(lcsi.stringIndex);
            auto it = std::search(str.begin(), str.end(),
                concatString.begin() + suffixIndex,
                concatString.begin() + suffixIndex + lcsi.subStringLength);
            lcsi.subStringIndex = it - str.begin();
            if(lcsi.subStringLength > currentLcsLength) lcsIndexes.clear();
            lcsIndexes.push_back(lcsi);
        }
        begin++;
    }
    return lcsIndexes;
}

std::string findLongestCommonSubstring(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    auto result = findLongestCommonSubstringIndexes(strings, minimumStringsCount);
    if(result.empty()) return "";
    if(result[0].subStringLength == 0) return "";
    size_t from = result[0].subStringIndex;
    return strings.at(result[0].stringIndex).substr(from, result[0].subStringLength);
}

}
