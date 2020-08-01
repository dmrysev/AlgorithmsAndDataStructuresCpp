#include "linked_list/working_with_std_list.h"

#include <algorithm>
#include <iostream>
#include <list>

namespace AlgorithmsAndDataStructures::Core::LinkedList::WorkingWithStdList {

void stdListTest() {
    // Create a list containing integers
    std::list<int> l = { 7, 5, 16, 8 };

    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);

    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }

    // Iterate and print values of the list
    for (int n : l) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

}
