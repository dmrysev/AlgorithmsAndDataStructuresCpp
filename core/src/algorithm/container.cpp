#include "algorithm/container.h"

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
    return shiftRightDequeImpl(values, shiftsCount);
}

int findUnpairedValue(const std::vector<int>& values) {
    if(values.empty()) throw std::invalid_argument{"values must be non empty"};
    if(values.size() % 2 == 0) throw std::invalid_argument{"values must contain odd number of elements"};
    if(values.size() == 1) return values.front();
    std::vector<int> unpairedValues;
    for(int i: values) {
        auto it = std::find(unpairedValues.begin(), unpairedValues.end(), i);
        if(it == unpairedValues.end()) {
            unpairedValues.push_back(i);
        }
        else {
            unpairedValues.erase(it);
        }
    }
    if(unpairedValues.empty()) throw std::runtime_error{"Unpaired value was not found"};
    if(unpairedValues.size() > 1) throw std::runtime_error{"More than one unpaired value was found"};
    return unpairedValues.front();
    return 0;
}


}
