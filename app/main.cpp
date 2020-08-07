#include "suffix_array.h"
#include "util/string.h"

#include <cmath>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace AlgorithmsAndDataStructures::SuffixArrayAlgorithms;

void print(auto iterable) {
    for(auto& item: iterable) std::cout << item << "\n";
    std::cout << std::endl;
}

int main() {
    auto str = "aabaac";
    SuffixArray sa = initSuffixArray(str);
    auto suffixes = getSuffixes(str, sa);
    print(suffixes);
    return 0;
}
