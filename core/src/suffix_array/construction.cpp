#include "suffix_array/construction.h"

#include <set>

namespace AlgorithmsAndDataStructures::Core::SuffixArray::Construction {

std::vector<size_t> initSuffixArray(const std::string& str) {
    std::set<std::pair<std::string, size_t> > suffices;
    for(size_t i = 0; i < str.size(); i++) {
        suffices.insert({ str.substr(i, str.size()), i });
    }
    std::vector<size_t> suffixArray(suffices.size());
    size_t i = 0;
    for(auto& [suffix, index]: suffices) {
        suffixArray[i++] = index;
    }
    return suffixArray;
}


}
