#include "util/string.h"

#include <random>

namespace Util::String {


std::string generateRandomString(size_t strSize, char from, char to) {
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{from, to};
    std::string randStr(strSize, '\0');
    for(char& dis: randStr) dis = static_cast<char>(distribution(generator));
    return randStr;
}

std::string generateRandomString(size_t strSize) {
    return generateRandomString(strSize, 'A', 'z');
}


}
