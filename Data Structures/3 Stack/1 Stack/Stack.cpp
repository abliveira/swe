#include <iostream>
using namespace std;

/*
    A stack is a linear data structure that follows the Last In, First Out (LIFO) principle, 
    where the last element added is the first to be removed.

    Note:
        - For simplicity and convenience, the C++ Standard Library offers a stack container (`std::stack`) that provides the same functionality with built-in memory management. 
        - Using the library version can eliminate the need for manual memory management and linked list structures.
        
    Basic operations:
        - Push: Add an element to the top of the stack.
        - Pop: Remove the top element from the stack.
        - Peek: Retrieve the top element without removing it (not implemented in this version).
        - isEmpty: Check if the stack is empty.

    Use Cases:
        - Stacks are commonly used in algorithms for expression evaluation, backtracking, undo/redo functionality, and managing function calls in recursion.

    Advantages:
        - The stack can grow dynamically, eliminating the need for a predefined capacity.
        - Both push and pop operations are O(1), as they involve direct manipulation of the `top` pointer.
        - Memory is allocated only when needed, which is suitable for environments with limited memory.

    Cons:
        - No random access: Unlike arrays, you cannot access elements by index; you can only interact with the top of the stack.
        - Memory overhead: Each element in the stack requires a node structure, which includes extra memory for pointers in addition to the data.
        - Non-contiguous memory: The stack's nodes are scattered in memory, which may lead to cache inefficiency compared to contiguous data structures like arrays.

    Time Complexity:
        - Push: O(1) — Adding an element to the top involves changing only the `top` pointer.
        - Pop: O(1) — Removing the top element also involves changing only the `top` pointer.
        - isEmpty: O(1) — Checking if the stack is empty only requires a comparison of the `top` pointer.
        - Print: O(n) — Traversing and printing the stack requires visiting all `n` nodes.

    Space Complexity:
        - O(n) — The space required is proportional to the number of nodes in the stack. Each node stores an integer and a pointer, which means the space used is directly tied to the number of elements in the stack.

    Implementation:
        - This program demonstrates a stack using a singly linked list.
        - Each node contains an integer `data` and a pointer to the next node.
        - The `Stack` class manages the linked list, with the `top` pointer representing the stack's top element.
        - Dynamic memory allocation is used to create and delete nodes as needed, ensuring efficient memory usage.
        - The destructor ensures all dynamically allocated nodes are properly deleted, preventing memory leaks.
*/


class Node {
public:
    int data;  // Data to store in the node
    Node* next;  // Pointer to the next node in the stack

    // Constructor to initialize the node with data
    Node(int x) {
        data = x;
        next = nullptr;  // Initially, no node is linked after this one
    }
};

class Stack {
public:
    Node* top;  // Pointer to the top of the stack

    // Constructor to initialize the stack
    Stack() {
        top = nullptr;  // Start with an empty stack
    }

    // Destructor to delete all nodes in the stack and avoid memory leaks
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push a new node onto the stack
    void push(Node* n) {
        n->next = top;  // Link the new node to the current top
        top = n;  // Update the top pointer to the new node
    }

    // Pop the top node from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return;
        }
        Node* n = top;  // Store the current top node
        top = top->next;  // Move top to the next node
        delete n;  // Delete the old top node to free memory
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;  // The stack is empty if top is null
    }

    // Print all elements of the stack
    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* ptr = top;  // Start from the top of the stack
        while (ptr != nullptr) {
            cout << ptr->data << endl;  // Print the data of the current node
            ptr = ptr->next;  // Move to the next node
        }
    }
};

int main() {
    Stack S;  // Create a stack object

    // Create nodes with data to push onto the stack
    Node* n1 = new Node(67);
    Node* n2 = new Node(42);
    Node* n3 = new Node(3);

    // Push the nodes onto the stack (in LIFO order)
    S.push(n1);
    S.push(n2);
    S.push(n3);

    // Print the stack contents after pushing elements
    cout << "Stack contents after pushes:" << endl;
    S.print();

    cout << endl;

    // Pop one element from the stack
    S.pop();

    // Print the stack contents after popping the top element
    cout << "Stack contents after pop:" << endl;
    S.print();

    // No need to explicitly delete nodes since the destructor handles it
    return 0;
}
