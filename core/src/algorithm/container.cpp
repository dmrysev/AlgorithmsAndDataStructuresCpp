#include "algorithm/container.h"

#include <map>
#include <deque>
#include <stdexcept>
#include <algorithm>

namespace Algorithm::Container {

namespace {

std::vector<int> shiftRightDequeImpl(const std::vector<int>& values, int shiftsCount) {
    std::deque<int> deque{values.begin(), values.end()};
    for(int i = 0; i < shiftsCount; i++) {
        int back = deque.back();
        deque.pop_back();
        deque.push_front(back);
    }
    return {deque.begin(), deque.end()};
}

std::vector<int> shiftRightNewVectorImpl(const std::vector<int>& values, int shiftsCount) {
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

std::vector<int> shiftRightIteratorsArithmeticImpl(const std::vector<int>& values, int shiftsCount) {
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
    return shiftRightIteratorsArithmeticImpl(values, shiftsCount);
}

int findUnpairedValue(const std::vector<int>& values) {
    std::unordered_map<int, bool> unpairedValues;
    for(int i: values) unpairedValues[i] = !unpairedValues[i];
    for(auto& pair: unpairedValues) if(pair.second == true) return pair.first;
    throw std::runtime_error{"Unpaired value was not found"};
}


}
