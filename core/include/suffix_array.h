#pragma once

#include <string>
#include <vector>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

using SuffixArray = std::vector<size_t>;
using LongestCommonSuffixArray = std::vector<size_t>;

SuffixArray initSuffixArray(const std::string& str);

std::vector<std::string> getSuffixes(const std::string& str, const SuffixArray& sa);

LongestCommonSuffixArray initLongestCommonPrefixArray(
    const SuffixArray& suffixArray,
    const std::string& str);

LongestCommonSuffixArray initLongestCommonPrefixArray(const std::string& str);

size_t findSubstringsCount(const std::string& str);
size_t findRepeatedSubstringsCount(const std::string& str);
size_t findUniqueSubstringsCount(const std::string& str);

}

