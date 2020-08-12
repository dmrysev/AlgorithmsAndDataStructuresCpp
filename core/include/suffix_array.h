#pragma once

#include <string>
#include <vector>
#include <optional>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

using SuffixArray = std::vector<size_t>;
SuffixArray initSuffixArray(const std::string& str);

std::vector<std::string> getSuffixes(const std::string& str, const SuffixArray& sa);

using LongestCommonPrefixArray = std::vector<size_t>;
LongestCommonPrefixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str);

LongestCommonPrefixArray initLongestCommonPrefixArray(const std::string& str);

size_t findSubstringsCount(const std::string& str);
size_t findRepeatedSubstringsCount(const std::string& str);
size_t findUniqueRepeatedSubstringsCount(const std::string& str);
size_t findUniqueSubstringsCount(const std::string& str);

struct LongestCommonSubstringIndex {
    size_t stringIndex = 0;
    size_t subStringIndex = 0;
    size_t subStringLength = 0;
};
inline bool operator==(const LongestCommonSubstringIndex& a, const LongestCommonSubstringIndex& b) {
    return a.stringIndex == b.stringIndex &&
        a.subStringIndex == b.subStringIndex &&
        a.subStringLength == b.subStringLength;
}
std::vector<LongestCommonSubstringIndex> findLongestCommonSubstringIndexes(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

std::optional<std::string> findLongestCommonSubstring(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

std::vector<std::string> findLongestCommonSubstrings(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

}

