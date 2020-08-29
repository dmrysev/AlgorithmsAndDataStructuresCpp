#include "algorithm/numeric.h"

#include <iostream>

using namespace Algorithm::Numeric;

int naive(int from, int to, int divisor) {
    int count = 0;
    for(int i = from; i <= to; i++) {
        if(i % divisor == 0) count++;
    }
    return count;
}

int main() {
    std::cout << naive(27, 276, 34) << std::endl;

    return 0;
}
