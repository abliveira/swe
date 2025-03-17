#include <iostream>
using namespace std;

/*
    This implementation of the stack differs from the linked list version by using a statically 
    allocated array (arr[]) to store the elements instead of dynamically created nodes. The stack 
    is now limited to a fixed size defined by the constant MAX, meaning it cannot dynamically grow 
    as in the linked list version. 

    Operations like push and pop are handled by directly manipulating the top index, which tracks 
    the position of the last inserted element, rather than updating pointers as in the linked list. 

    Additionally, the stack now includes an overflow check using the isFull() function to prevent 
    exceeding the array’s capacity. By using an array, this version benefits from contiguous memory 
    storage, which can improve cache performance, but at the cost of flexibility since the stack size 
    is fixed.
*/


const int MAX = 10;  // Maximum stack capacity

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element

public:
    // Constructor: Initializes the stack
    Stack() {
        top = -1;  // Start with an empty stack
    }

    // Checks if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Checks if the stack is full
    bool isFull() const {
        return top == MAX - 1;
    }

    // Push: Adds an element to the stack
    void push(int item) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << item << "." << endl;
            return;
        }
        arr[++top] = item;  // Increment top and insert the item
    }

    // Pop: Removes and returns the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1;  // Return -1 to indicate an error
        }
        return arr[top--];  // Return the top element and decrement `top`
    }

    // Print: Displays all elements in the stack
    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack contents (top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;  // Create a stack object

    // Push elements onto the stack
    s.push(11);
    s.push(23);
    s.push(-8);
    s.push(16);
    s.push(27);
    s.push(14);
    s.push(20);
    s.push(39);
    s.push(2);
    s.push(15);

    // Attempt to push beyond the stack's capacity
    s.push(7);  // This should trigger a "Stack is full!" message

    // Print stack contents
    cout << "\nStack contents after pushes:" << endl;
    s.print();

    // Pop elements from the stack
    cout << "\nPopping elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Item popped: " << s.pop() << endl;
    }

    // Print stack contents after popping
    cout << "\nStack contents after pops:" << endl;
    s.print();

    return 0;
}
