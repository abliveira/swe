#include <iostream>
#include <queue>
using namespace std;

/*
    Demonstrates the usage of `std::queue` from the C++ Standard Library.

    - Follows the FIFO (First In, First Out) principle.
    - Provides essential operations: push, pop, front, empty, and size.
    - Uses `std::queue<int>` directly in `main()` without a custom class.

    Complexity:
    - Enqueue (push): O(1)
    - Dequeue (pop): O(1)
    - Front access: O(1)
    - isEmpty: O(1)
    - Print: O(n) (requires copying and iterating)

    Space Complexity:
    - O(n) — Proportional to the number of stored elements.
*/


void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    while (!q.empty()) {
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "NULL" << endl;
}

int main() {
    queue<int> q;  // Create a queue of integers

    // Enqueue elements
    q.push(7);
    q.push(78);
    q.push(11);

    // Print queue contents after enqueue
    cout << "Queue contents after enqueues:" << endl;
    printQueue(q);

    // Reinsert elements for demonstration
    q.push(7);
    q.push(78);
    q.push(11);

    // Dequeue one element
    q.pop();

    // Print queue contents after dequeue
    cout << "Queue contents after dequeue:" << endl;
    printQueue(q);

    return 0;
}
