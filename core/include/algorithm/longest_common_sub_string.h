#pragma once

#include <set>
#include <string>
#include <vector>
#include <optional>

namespace Algorithm::LongestCommonSubString {

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

std::set<std::string> findLongestCommonUniqueSubstrings(
    const std::vector<std::string>& strings,
    std::optional<size_t> minimumStringsCount = {});

}

