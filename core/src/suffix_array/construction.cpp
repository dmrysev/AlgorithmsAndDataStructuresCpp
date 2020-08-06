#include "suffix_array/construction.h"

#include <set>

namespace AlgorithmsAndDataStructures::Core::SuffixArray::Construction {

std::vector<size_t> initSuffixArray(const std::string& str) {
    auto compare = [&](size_t a, size_t b) {
        std::string suffixA = str.substr(a, str.size());
        std::string suffixB = str.substr(b, str.size());
        return suffixA < suffixB;
    };
    std::set<size_t, decltype(compare)> suffices(compare);
    for(size_t i = 0; i < str.size(); i++) {
        suffices.insert(i);
    }
    return {suffices.begin(), suffices.end()};
}


}
