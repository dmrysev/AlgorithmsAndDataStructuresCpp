#pragma once

#include <random>

namespace Util::Numeric {

template<class T>
T randomNumber(T from, T to) {
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<T> distribution{from, to};
    return distribution(generator);
}

}
