#include "suffix_array.h"
#include "util/string.h"
#include "util/collection.h"

#include <cmath>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <map>

using namespace std::chrono;
using namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms;

void print(auto& iterable) {
    for(auto& item: iterable) std::cout << item << "\n";
    std::cout << std::endl;
}

int main() {
    auto str = "abcabcabc";
    SuffixArray sa = initSuffixArray(str);
    LongestCommonPrefixArray lcsa = initLongestCommonPrefixArray(sa, str);
    auto suffixes = getSuffixes(str, sa);
    print(suffixes);
    print(lcsa);
    size_t urc = findUniqueRepeatedSubstringsCount(str);
    std::cout << urc << std::endl;
    return 0;
}
