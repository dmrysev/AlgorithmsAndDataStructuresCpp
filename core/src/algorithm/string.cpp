#include "algorithm/string.h"
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

namespace Algorithm::String {

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
//    auto getLcpIndex = [&] (size_t begin, size_t end) {

//    };
//    auto getLcpLength = [&](size_t begin, size_t end) {
//        auto it = lcpa.begin();
//        return *std::min_element(it + begin, it + end);
//    };
    auto getLcpIterator = [&] (size_t begin, size_t end) {
        auto it = lcpa.begin();
        return std::min_element(it + begin + 1, it + end + 1);
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
        auto lcpIteratorForWindow = getLcpIterator(begin, end);
        size_t lcpIndexForWindow = lcpIteratorForWindow - lcpa.begin();
        size_t lcpLengthForWindow = *lcpIteratorForWindow;
        size_t currentLcsLength = lcsIndexes.empty() ? 0 : lcsIndexes[0].subStringLength;
        if(lcpLengthForWindow >= currentLcsLength) {
            LongestCommonSubstringIndex lcsi;
            size_t suffixIndex = suffixArray[lcpIndexForWindow];
            lcsi.stringIndex = getStringIndex(suffixIndex);
            lcsi.subStringLength = lcpLengthForWindow;
            const std::string& str = strings.at(lcsi.stringIndex);
            auto it = std::search(str.begin(), str.end(),
                concatString.begin() + suffixIndex,
                concatString.begin() + suffixIndex + lcsi.subStringLength);
            lcsi.subStringIndex = it - str.begin();
            if(lcsi.subStringLength > currentLcsLength) lcsIndexes.clear();
            if(!Util::Collection::contains(lcsIndexes, lcsi)) lcsIndexes.push_back(lcsi);
        }
        begin++;
    }
    return lcsIndexes;
}

std::optional<std::string> findLongestCommonSubstring(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    auto result = findLongestCommonSubstringIndexes(strings, minimumStringsCount);
    if(result.empty()) return {};
    size_t from = result[0].subStringIndex;
    return strings.at(result[0].stringIndex).substr(from, result[0].subStringLength);
}

std::vector<std::string> findLongestCommonSubstrings(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    auto result = findLongestCommonSubstringIndexes(strings, minimumStringsCount);
    std::vector<std::string> subStrings;
    for(LongestCommonSubstringIndex lcsIndex: result) {
        size_t from = lcsIndex.subStringIndex;
        subStrings.emplace_back(strings.at(lcsIndex.stringIndex).substr(from, lcsIndex.subStringLength));
    }
    return subStrings;
}

std::set<std::string> findLongestCommonUniqueSubstrings(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount)
{
    auto result = findLongestCommonSubstringIndexes(strings, minimumStringsCount);
    std::set<std::string> subStrings;
    for(LongestCommonSubstringIndex lcsIndex: result) {
        size_t from = lcsIndex.subStringIndex;
        subStrings.insert(strings.at(lcsIndex.stringIndex).substr(from, lcsIndex.subStringLength));
    }
    return subStrings;
}

}
