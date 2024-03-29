#include "algorithm/container.h"
#include "data_structure/prefix_sum.h"

#include <map>
#include <set>
#include <deque>
#include <numeric>
#include <stdexcept>
#include <algorithm>
#include <unordered_set>

namespace Algorithm::Container {

namespace ShiftRightImpl {

std::vector<int> deque(const std::vector<int>& values, int shiftsCount) {
    std::deque<int> deque{values.begin(), values.end()};
    for(int i = 0; i < shiftsCount; i++) {
        int back = deque.back();
        deque.pop_back();
        deque.push_front(back);
    }
    return {deque.begin(), deque.end()};
}

std::vector<int> newVector(const std::vector<int>& values, int shiftsCount) {
    std::vector<int> newVector(values.size());
    for(int i = 0; i < values.size(); i++) {
        if(i + shiftsCount < values.size()) {
            newVector[i + shiftsCount] = values[i];
        }
        else {
            size_t newIndex = shiftsCount - (values.size() - i);
            newVector[newIndex] =  values[i];
        }
    }
    return newVector;
}

std::vector<int> iteratorArithmetic(const std::vector<int>& values, int shiftsCount) {
    std::vector<int> newVector;
    newVector.insert(newVector.end(), values.end() - shiftsCount, values.end());
    newVector.insert(newVector.end(), values.begin(), values.end() - shiftsCount);
    return newVector;
}

}

std::vector<int> shiftRight(const std::vector<int>& values, int shiftsCount) {
    if(values.size() <= 1) return values;
    if(shiftsCount == values.size()) return values;
    else if(shiftsCount > values.size()) shiftsCount = shiftsCount - values.size();
    return ShiftRightImpl::iteratorArithmetic(values, shiftsCount);
}

namespace FindUnpairedValueImpl {

int preInitVector(const std::vector<int>& values) {
    std::vector<bool> unpairedValues(1000000000);
    for(int i: values) unpairedValues[i] = !unpairedValues[i];
    auto it = std::find(unpairedValues.begin(), unpairedValues.end(), true);
    if(it == unpairedValues.end()) throw std::runtime_error{"Unpaired value was not found"};
    return it - unpairedValues.begin();
}

int unorderedSet(const std::vector<int>& values) {
    std::unordered_set<int> unpairedValues;
    for(int i: values) {
        auto it = unpairedValues.find(i);
        if(it == unpairedValues.end()) unpairedValues.insert(i);
        else unpairedValues.erase(it);
    }
    return *unpairedValues.begin();
}

int unorderedMap(const std::vector<int>& values) {
    std::unordered_map<int, bool> unpairedValues;
    for(int i: values) unpairedValues[i] = !unpairedValues[i];
    for(auto& pair: unpairedValues) if(pair.second == true) return pair.first;
    throw std::runtime_error{"Unpaired value was not found"};
}

}

int findUnpairedValue(const std::vector<int>& values) {
    return FindUnpairedValueImpl::unorderedSet(values);
}

namespace FindMissingElementImpl {

int usingSet(const std::vector<int>& values) {
    std::set sortedValues(values.begin(), values.end());
    auto it = std::adjacent_find(sortedValues.begin(), sortedValues.end(), [&] (int a, int b) {
        return b - a > 1;
    });
    if(it == sortedValues.end()) throw std::runtime_error{"Missing element was not found"};
    int missingElement = *it;
    return ++missingElement;
}

int usingSortedVector(const std::vector<int>& values) {
    auto sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());
    if(sortedValues.front() != 1) return 1;
    if(sortedValues.back() != values.size() + 1) return values.size() + 1;
    auto it = std::adjacent_find(sortedValues.begin(), sortedValues.end(), [&] (int a, int b) {
        return b - a > 1;
    });
    if(it == sortedValues.end()) throw std::runtime_error{"Missing element was not found"};
    int missingElement = *it;
    return ++missingElement;
}

int usingIndexArray(const std::vector<int>& values) {
    std::vector<bool> indexArray(values.size() + 1, false);
    for(int i = 0; i < values.size(); i++) {
        int value = values[i];
        if(value < 1 || value >= indexArray.size()) continue;
        indexArray[value] = true;
    }
    auto it = std::find(indexArray.begin() + 1, indexArray.end(), false);
    return it - indexArray.begin();
}

}

int findMissingElement(const std::vector<int>& values) {
    if(values.empty()) return 1;
    return FindMissingElementImpl::usingIndexArray(values);
}

namespace TapeEquilibriumImpl {

int naiveApproach(const std::vector<int>& values) {
    int smallestDifference = std::numeric_limits<int>::max();
    for(size_t i = 1; i < values.size(); i++) {
        int firstHalfSum = std::accumulate(values.begin(), values.begin() + i, 0);
        int secondHalfSum = std::accumulate(values.begin() + i, values.end(), 0);
        int difference = std::abs(firstHalfSum - secondHalfSum);
        if(difference < smallestDifference) smallestDifference = difference;
    }
    return smallestDifference;
}

int usingPrefixSum(const std::vector<int>& values) {
    int smallestDifference = std::numeric_limits<int>::max();
    auto prefixSum = DataStructure::PrefixSum::initPrefixSum(values);
    for(size_t i = 0; i < values.size() - 1; i++) {
        int firstHalfSum = prefixSum[i+1] - prefixSum.front();
        int secondHalfSum = prefixSum.back() - prefixSum[i+1];
        int difference = std::abs(firstHalfSum - secondHalfSum);
        if(difference < smallestDifference) smallestDifference = difference;
    }
    return smallestDifference;
}

}

int tapeEquilibrium(const std::vector<int>& values) {
    return TapeEquilibriumImpl::usingPrefixSum(values);
}

namespace FindEarliestAvailablePathImpl {

int vectorOfBools(const std::vector<int>& values, int distance) {
    std::vector<bool> path(values.size() + 1, false);
    path[0] = true;
    auto isPathAvailable = [&] {
        for(size_t i = 1; i <= distance; i++) {
            if(path[i] == false) return false;
        }
        return true;
    };
    for(size_t i = 0; i < values.size(); i++) {
        int value = values[i];
        path[value] = true;
        if(isPathAvailable()) return i;
    }
    return -1;
}

int usingIndexMap(const std::vector<int>& values, int distance) {
    int maxIndex = 0;
    std::unordered_map<int, int> valuesIndexes;
    for(int i = 0; i < values.size(); i++) {
        int value = values[i];
        if(valuesIndexes.count(value) == 0) valuesIndexes[value] = i;
    }
    for(int i = 1; i <= distance; i++) {
        if(valuesIndexes.count(i) == 0) return -1;
        int index = valuesIndexes[i];
        if(index > maxIndex) maxIndex = index;
    }
    return maxIndex;
}

int usingIndexArray(const std::vector<int>& values, int distance) {
    int maxIndex = 0;
    std::vector<int> indexArray(distance + 1, -1);
    for(int i = 0; i < values.size(); i++) {
        int value = values[i];
        if(indexArray[value] == -1) indexArray[value] = i;
    }
    for(int i = 1; i <= distance; i++) {
        if(indexArray[i] == -1) return -1;
        int index = indexArray[i];
        if(index > maxIndex) maxIndex = index;
    }
    return maxIndex;
}

}

int findEarliestAvailablePath(const std::vector<int>& values, int distance) {
    return FindEarliestAvailablePathImpl::usingIndexArray(values, distance);
}

}
