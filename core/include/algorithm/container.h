#pragma once

#include <vector>

namespace Algorithm::Container {

std::vector<int> shiftRight(const std::vector<int>& values, int shiftsCount);
int findUnpairedValue(const std::vector<int>& values);
int findMissingElement(const std::vector<int>& values);
int tapeEquilibrium(const std::vector<int>& values);

}
