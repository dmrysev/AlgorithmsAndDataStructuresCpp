#include <iostream>
#include "stack/multiplication.hpp"

using namespace AlgorithmsAndDataStructures;

int main() {
    double result2 = MyDynamicLib::Multiplication::multBy2(3);
    std::cout << "3 * 2 = " << result2 << std::endl;

    return 0;
}
