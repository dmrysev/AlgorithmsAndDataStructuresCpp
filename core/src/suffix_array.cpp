#include "suffix_array.h"

#include <set>

namespace AlgorithmsAndDataStructures::SuffixArray {

std::vector<size_t> initSuffixArray(const std::string& str) {
    auto compare = [&](size_t a, size_t b) {
        return std::lexicographical_compare(str.begin() + a, str.end(),
                                            str.begin() + b, str.end());
    };
    std::set<size_t, decltype(compare)> suffices(compare);
    for(size_t i = 0; i < str.size(); i++) {
        suffices.insert(i);
    }
    return {suffices.begin(), suffices.end()};
}


}
