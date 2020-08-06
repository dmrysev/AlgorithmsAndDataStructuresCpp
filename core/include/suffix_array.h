#pragma once

#include <string>
#include <vector>

namespace AlgorithmsAndDataStructures::SuffixArray {

std::vector<size_t> initSuffixArray(const std::string& str);

std::vector<size_t> initLongestCommonPrefixArray(
    const std::vector<size_t>& suffixArray,
    const std::string& str);

std::vector<size_t> initLongestCommonPrefixArray(const std::string& str);

}

