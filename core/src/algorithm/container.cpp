#include "algorithm/container.h"

#include <map>
#include <set>
#include <deque>
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

int findMissingElement(const std::vector<int>& values) {
    std::set<int> sortedValues{values.begin(), values.end()};
    auto it = std::adjacent_find(sortedValues.begin(), sortedValues.end(), [&] (int a, int b) {
        return b - a > 1;
    });
    if(it == sortedValues.end()) throw std::runtime_error{"Missing element was not found"};
    int missingElement = *it;
    return ++missingElement;
}


}
