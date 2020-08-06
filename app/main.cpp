#include <iostream>
#include <chrono>
#include <random>
#include "suffix_array.h"

using namespace std::chrono;
using namespace AlgorithmsAndDataStructures;

int main() {
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{'a', 'z'};
    size_t size = std::pow(10ll, 6ll);
    std::string rand_str(size, '\0');
    for(char& dis: rand_str) dis = static_cast<char>(distribution(generator));
    auto begin = high_resolution_clock::now();
    auto suffixArray = SuffixArray::initSuffixArray(rand_str);
    auto elapsed = high_resolution_clock::now() - begin;
    std::cout << duration_cast<milliseconds>(elapsed).count() << std::endl;
    return 0;
}
