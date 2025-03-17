#include <iostream>
#include <stack>  // Importing the standard stack library

using namespace std;

/*
    This program demonstrates the usage of the C++ Standard Library `std::stack`.

    Features:
    - Uses the LIFO (Last In, First Out) principle.
    - Provides fundamental operations: push, pop, top, empty, and size.
    - Uses `std::stack<int>` directly in `main()` without a custom class.

    Time Complexity:
    - Push: O(1)
    - Pop: O(1)
    - Top: O(1)
    - isEmpty: O(1)
    - Print: O(n) (requires copying and iterating)

    Space Complexity:
    - O(n) — Directly proportional to the number of elements in the stack.
*/

// Function to print stack contents
void printAndEmptyStack(stack<int> s) {
    cout << "Printing and emptying stack (LIFO order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> S;  // Creating a stack using the standard library

    // push() - Adding elements to the stack
    cout << "Pushing elements onto the stack..." << endl;
    S.push(67);
    S.push(42);
    S.push(3);
    cout << "3 elements pushed.\n" << endl;

    // size() - Getting the number of elements
    cout << "Stack size: " << S.size() << " elements" << endl;

    // top() - Accessing the top element
    cout << "Top element: " << S.top() << endl;

    // pop() - Removing the top element
    cout << "Popping top element: " << S.top() << endl;
    S.pop();

    // Showing updated stack details after pop
    cout << "New top element after pop: " << S.top() << endl;
    cout << "Stack size after pop: " << S.size() << " elements\n" << endl;

    // print and empty operation
    printAndEmptyStack(S);

    // empty() - Checking if stack is empty
    cout << "\nIs stack empty? " << (S.empty() ? "Yes" : "No") << endl;

    return 0;
}
