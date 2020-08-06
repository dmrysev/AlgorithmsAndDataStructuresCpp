#include <iostream>
#include <chrono>
#include <random>
#include "suffix_array.h"

using namespace std::chrono;
using namespace AlgorithmsAndDataStructures;

int main() {
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{'a', 'z'};
    size_t size = std::pow(10ll, 1ll);
    std::string randStr(size, '\0');
    for(char& dis: randStr) dis = static_cast<char>(distribution(generator));
    auto begin = high_resolution_clock::now();
    auto suffixArray = SuffixArray::initSuffixArray(randStr);
    auto lcpa = SuffixArray::initLongestCommonPrefixArray(suffixArray, randStr);
    auto elapsed = high_resolution_clock::now() - begin;
    std::cout << duration_cast<milliseconds>(elapsed).count() << std::endl;
    return 0;
}
