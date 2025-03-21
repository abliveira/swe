#include <iostream>
using namespace std;

/*
    A queue is a linear data structure that follows the First In, First Out (FIFO) principle, 
    where the first element added is the first to be removed.

    Note:
        - For simplicity and convenience, the C++ Standard Library provides a queue container (`std::queue`) 
          that offers the same functionality with built-in memory management.
        - Using the library version eliminates the need for manual memory management and linked list structures.
        
    Basic operations:
        - Enqueue: Add an element to the back of the queue.
        - Dequeue: Remove the element from the front of the queue.
        - isEmpty: Check if the queue is empty.

    Use Cases:
        - Queues are widely used in process scheduling, print job management, 
          call center systems, and algorithms like Breadth-First Search (BFS).

    Advantages:
        - The queue can dynamically grow, eliminating the need for a predefined capacity.
        - Insertions and deletions are efficient, with O(1) complexity in linked list implementations.

    Cons:
        - No random access: Unlike arrays, you cannot access elements by index; you can only interact with the front and back.
        - Memory overhead: Each element requires an extra pointer, increasing memory usage compared to arrays.

    Time Complexity:
        - Enqueue: O(1) — Adding an element updates only the `back` pointer.
        - Dequeue: O(1) — Removing an element updates only the `front` pointer.
        - isEmpty: O(1) — Checking if the queue is empty only requires a pointer comparison.
        - Print: O(n) — Traversing and printing the queue requires visiting all `n` nodes.

    Space Complexity:
        - O(n) — The space required is proportional to the number of nodes in the queue.

    Implementation:
        - This program demonstrates a queue using a singly linked list.
        - Each node contains an integer `data` and a pointer to the next node.
        - The `Queue` class manages the linked list, with `front` and `back` pointers representing both ends of the queue.
        - The destructor ensures all dynamically allocated nodes are properly deleted, preventing memory leaks.
*/

class Node {
public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the queue

    // Constructor to initialize the node with a value
    Node(int x) {
        data = x;
        next = nullptr;  // Initially, no node is linked to this one
    }
};

class Queue {
public:
    Node* front;  // Pointer to the front of the queue
    Node* back;   // Pointer to the back of the queue

    // Constructor to initialize an empty queue
    Queue() {
        front = back = nullptr;
    }

    // Destructor to delete all nodes in the queue and avoid memory leaks
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Add a new node to the queue
    void enqueue(Node* n) {
        if (isEmpty()) {
            front = back = n;  // If the queue is empty, both pointers reference the new node
        } else {
            back->next = n;  // Link the last node to the new node
            back = n;        // Update `back` to the new node
        }
    }

    // Remove the front node from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return;
        }
        Node* n = front;  // Store the front node
        front = front->next;  // Move front to the next node
        if (front == nullptr) {
            back = nullptr;  // If the queue becomes empty, reset `back`
        }
        delete n;  // Free memory of the removed node
    }

    // Print all elements of the queue
    void print() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* ptr = front;  // Start from the front of the queue
        while (ptr != nullptr) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;  // Move to the next node
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue Q;  // Create a queue object

    // Create nodes with data to enqueue
    Node* n1 = new Node(7);
    Node* n2 = new Node(78);
    Node* n3 = new Node(11);

    // Enqueue nodes into the queue (FIFO order)
    Q.enqueue(n1);
    Q.enqueue(n2);
    Q.enqueue(n3);

    // Print the queue contents after enqueues
    cout << "Queue contents after enqueues:" << endl;
    Q.print();

    cout << endl;

    // Dequeue one element from the queue
    Q.dequeue();

    // Print the queue contents after dequeue
    cout << "Queue contents after dequeue:" << endl;
    Q.print();

    return 0;
}
