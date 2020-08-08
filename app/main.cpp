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
//    findLongestCommonSubstring({"abca", "bcad", "daca"});
    std::cout << findLongestCommonSubstring({"AABC", "BCDC", "BCDE", "CDED"}, 2) << std::endl;
    return 0;
}
