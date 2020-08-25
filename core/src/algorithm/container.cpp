#include "algorithm/container.h"

#include <deque>

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
    newVector.insert(newVector.end(), values.begin(), values.begin() + shiftsCount - 1);
    return newVector;
}

}

std::vector<int> shiftRight(const std::vector<int>& values, int shiftsCount) {
    if(shiftsCount == values.size()) return values;
    else if(shiftsCount > values.size()) shiftsCount = shiftsCount - values.size();
    return shiftRightIteratorsArithmeticImpl(values, shiftsCount);
}


}
