#pragma once

#include <set>
#include <string>
#include <vector>
#include <optional>

namespace DataStructure::SuffixArray {

using SuffixArray = std::vector<size_t>;
SuffixArray initSuffixArray(const std::string& str);

std::vector<std::string> getSuffixes(const std::string& str, const SuffixArray& sa);

using LongestCommonPrefixArray = std::vector<size_t>;
LongestCommonPrefixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str);

LongestCommonPrefixArray initLongestCommonPrefixArray(const std::string& str);

}

