#include "priority_queue.hpp"
#include <iostream>

int main() {
    priority_queue<int> pq(10); // Create a priority queue with a capacity of 10

    // Enqueue some elements with priorities
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 2);

    // Check the size of the queue
    std::cout << "Size of the queue: " << pq.size() << std::endl;

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (pq.empty() ? "Yes" : "No") << std::endl;

    // Access and print elements using operator[]
    for (int i = 0; i <= pq.size(); ++i) {
        int elem_value = pq.at(i);
        std::cout << "Element " << i << ": Value = " << elem_value << std::endl;
    }

    // Dequeue the element with the highest priority
    pq.dequeue();

    // Check the size of the queue again
    std::cout << "Size of the queue after dequeue: " << pq.size() << std::endl;

    // Push a new element with a priority
    pq.push(50, 4);

    // Dequeue the element with the highest priority again
    pq.pop();

    // Check the size and elements after pop
    std::cout << "Size of the queue after pop: " << pq.size() << std::endl;

    for (int i = 0; i <= pq.size(); ++i) {
        int elem_value = pq.at(i);
        std::cout << "Element " << i << ": Value = " << elem_value << std::endl;
    }

    return 0;
}
