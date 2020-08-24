#pragma once

#include <set>
#include <string>
#include <vector>
#include <optional>

namespace Algorithm::RepeatedSubString {

size_t findSubstringsCount(const std::string& str);
size_t findRepeatedSubstringsCount(const std::string& str);
size_t findUniqueRepeatedSubstringsCount(const std::string& str);
size_t findUniqueSubstringsCount(const std::string& str);

}

