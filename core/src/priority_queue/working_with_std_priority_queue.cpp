#include "priority_queue/working_with_std_priority_queue.h"

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

namespace AlgorithmsAndDataStructures::Core::PriorityQueue::WorkingWithStdPriorityQueue {

namespace {

template<typename T> void printQueue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

}

void stdPriorityQueueTest() {
    std::priority_queue<int> q;

    for(int n: {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    printQueue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for(int n: {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    printQueue(q2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n: {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    printQueue(q3);
}

}
