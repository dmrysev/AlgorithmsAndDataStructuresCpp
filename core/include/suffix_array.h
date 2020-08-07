#pragma once

#include <string>
#include <vector>

namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms {

using SuffixArray = std::vector<size_t>;
using LongestCommonPrefixArray = std::vector<size_t>;

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

}

