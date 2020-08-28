#include "algorithm/numeric.h"

#include <iostream>

using namespace Algorithm::Numeric;

int main() {
    std::cout << countDivisible(15, 276, 43) << std::endl;
    std::cout << countDivisible(23, 986, 5) << std::endl;
    std::cout << countDivisible(48, 3477, 234) << std::endl;

    return 0;
}
