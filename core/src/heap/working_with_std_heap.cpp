#include "heap/working_with_std_heap.h"

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

namespace AlgorithmsAndDataStructures::Core::Heap::WorkingWithStdHeap {

void stdHeapTest() {
    std::cout << "Max heap:\n";

    std::vector<int> v { 3, 2, 4, 1, 5, 9 };

    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v.begin(), v.end());

    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::pop_heap(v.begin(), v.end());

    std::cout << "after pop_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    auto top = v.back();
    v.pop_back();
    std::cout << "former top element: " << top << '\n';

    std::cout << "after removing the former top element, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n' << '\n';

    std::cout << "Min heap:\n";

    std::vector<int> v1 { 3, 2, 4, 1, 5, 9 };

    std::cout << "initially, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v1.begin(), v1.end(), std::greater<>{});

    std::cout << "after make_heap, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';

    std::pop_heap(v1.begin(), v1.end(), std::greater<>{});

    std::cout << "after pop_heap, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';

    auto top1 = v1.back();
    v1.pop_back();
    std::cout << "former top element: " << top1 << '\n';

    std::cout << "after removing the former top element, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';
}


}
