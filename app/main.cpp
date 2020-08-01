#include <iostream>
#include "my_static_lib/addition.hpp"
#include "my_dynamic_lib/multiplication.hpp"

using namespace AlgorithmsAndDataStructures;

int main() {
    double result = MyStaticLib::Addition::add2(2);
    std::cout << "2 + 2 = " << result << std::endl;

    double result2 = MyDynamicLib::Multiplication::multBy2(3);
    std::cout << "3 * 2 = " << result2 << std::endl;

    return 0;
}
