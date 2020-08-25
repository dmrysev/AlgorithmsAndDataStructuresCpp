#include "algorithm/container.h"

#include <deque>

namespace Algorithm::Container {

namespace {

std::vector<int> shiftRightDequeImp(const std::vector<int>& values, int shiftsCount) {
    std::deque<int> deque{values.begin(), values.end()};
    for(int i = 0; i < shiftsCount; i++) {
        int back = deque.back();
        deque.pop_back();
        deque.push_front(back);
    }
    return {deque.begin(), deque.end()};
}

}

std::vector<int> shiftRight(const std::vector<int>& values, int shiftsCount) {
    return shiftRightDequeImp(values, shiftsCount);
}


}
