#include <iostream>
#include <deque>

using namespace std;

/*
    Demonstrates the usage of `std::deque` as a queue in C++.

    - While `std::deque` supports strict FIFO (First In, First Out) behavior, it also allows for flexible double-ended operations.
    - `std::deque` supports **both** FIFO and reverse (LIFO: Last In, First Out) operations efficiently, with O(1) time complexity for insertions and deletions at both ends.
    - Unlike `std::queue`, which only allows push at the back and pop at the front, `std::deque` provides more flexibility.

    Basic Operations:
    - **push_back(item)** → Adds an element to the rear of the queue (FIFO).
    - **pop_front()** → Removes the front element (FIFO).
    - **push_front(item)** → Adds an element to the front of the queue (used for reverse or LIFO operations).
    - **pop_back()** → Removes the last element (LIFO).
    - **front()** → Retrieves the front element without removing it (FIFO peek).
    - **back()** → Retrieves the last element without removing it (LIFO peek).
    - **size()** → Returns the number of elements in the deque.
*/

void printDeque(const deque<string>& dq) {
    if (dq.empty()) {
        cout << "Deque is empty!" << endl;
        return;
    }
    for (const auto& item : dq) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    deque<string> dq;

    // ----- Strict FIFO Queue Operations -----
    dq.push_back("a");  // Enqueue (add to rear)
    dq.push_back("b");
    dq.push_back("42");

    cout << "Queue after enqueues: ";
    printDeque(dq);  // Output: a b 42

    cout << "Front Peek: " << dq.front() << endl;  // Peek front (equivalent to front())

    dq.pop_front();  // Dequeue (remove from front)
    cout << "Queue after dequeue: ";
    printDeque(dq);  // Output: b 42

    // ----- Reverse Operations -----
    dq.push_front("X");  // Enqueue at front
    cout << "Queue after enqueue_front: ";
    printDeque(dq);  // Output: X b 42

    cout << "Back Peek: " << dq.back() << endl;  // Peek back (equivalent to back())

    dq.pop_back();  // Dequeue from back
    cout << "Queue after dequeue_back: ";
    printDeque(dq);  // Output: X b

    return 0;
}
