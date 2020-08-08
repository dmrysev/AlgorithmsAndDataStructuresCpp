#pragma once

#include <string>
#include <vector>
#include <optional>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

using SuffixArray = std::vector<size_t>;
using LongestCommonPrefixArray = std::vector<size_t>;

struct LongestCommonSubstringIndex {
    size_t stringIndex = 0;
    size_t subStringIndex = 0;
    size_t subStringLength = 0;
    std::string subString;

    bool operator==(const LongestCommonSubstringIndex& other) {
        return stringIndex == other.stringIndex &&
               subStringIndex == other.subStringIndex &&
               subStringLength == other.subStringLength;
    }
};

SuffixArray initSuffixArray(const std::string& str);

std::vector<std::string> getSuffixes(const std::string& str, const SuffixArray& sa);

LongestCommonPrefixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str);

LongestCommonPrefixArray initLongestCommonPrefixArray(const std::string& str);

size_t findSubstringsCount(const std::string& str);
size_t findRepeatedSubstringsCount(const std::string& str);
size_t findUniqueRepeatedSubstringsCount(const std::string& str);
size_t findUniqueSubstringsCount(const std::string& str);

LongestCommonSubstringIndex findLongestCommonSubstringIndex(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

std::string findLongestCommonSubstring(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

}

