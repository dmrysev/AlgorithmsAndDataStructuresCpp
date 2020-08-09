#pragma once

#include <string>

namespace Util::String {

std::string generateRandomString(size_t strSize);
std::string generateRandomString(size_t strSize, char from, char to);

}
