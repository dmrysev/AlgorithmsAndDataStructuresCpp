#pragma once

#include <string>
#include <vector>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

using SuffixArray = std::vector<size_t>;
using LongestCommonSuffixArray = std::vector<size_t>;

SuffixArray initSuffixArray(const std::string& str);

LongestCommonSuffixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str);

LongestCommonSuffixArray initLongestCommonPrefixArray(const std::string& str);

size_t findSubstringsCount(const std::string& str);
size_t findRepeatedSubstringsCount(const std::string& str);
size_t findUniqueSubstringsCount(const std::string& str);

}

