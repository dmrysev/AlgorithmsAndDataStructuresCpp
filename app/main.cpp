#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include "suffix_array.h"

using namespace std::chrono;
using namespace AlgorithmsAndDataStructures;

int main() {
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{'a', 'd'};
    size_t size = std::pow(10ll, 5ll);
    std::string randStr(size, '\0');
    for(char& dis: randStr) dis = static_cast<char>(distribution(generator));
    auto begin = high_resolution_clock::now();
//    auto suffixArray = SuffixArray::initSuffixArray(randStr);
    auto lcpa = SuffixArray::initLongestCommonPrefixArray(randStr);
    auto elapsed = high_resolution_clock::now() - begin;
    std::cout << "duration = " << duration_cast<milliseconds>(elapsed).count() << " ms" << std::endl;
    std::cout << "max lcp = " << *std::max_element(lcpa.begin(), lcpa.end()) << std::endl;
    return 0;
}
