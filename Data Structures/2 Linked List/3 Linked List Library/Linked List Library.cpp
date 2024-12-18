#include <iostream>
#include <list> // Linked list library
using namespace std;

/*
    This program demonstrates the use of the C++ Standard Template Library (STL) `std::list` container, 
    which implements a doubly linked list. The example showcases various linked list operations, including:

    - Adding elements at the front and back (`push_front` and `push_back`)
    - Accessing the front and back elements (`front` and `back`)
    - Removing elements from the front and back (`pop_front` and `pop_back`)
    - Inserting elements at specific positions
    - Removing specific elements by value
    - Reversing the list order
    - Sorting the list in ascending order

    The program highlights how `std::list` abstracts the complexity of linked list management, 
    offering efficient insertion and deletion operations while providing utility functions for common tasks.
    It demonstrates the flexibility and ease of use of STL containers for managing linked list data structures.
*/

int main() {
    // Create a list of integers
    list<int> linkedList;

    // Insert elements at the front
    linkedList.push_front(10);
    linkedList.push_front(20);

    // Insert elements at the back
    linkedList.push_back(30);
    linkedList.push_back(40);

    cout << "Initial List: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Access the front and back elements
    cout << "Front Element: " << linkedList.front() << endl;
    cout << "Back Element: " << linkedList.back() << endl;

    // Remove elements from the front and back
    linkedList.pop_front();
    linkedList.pop_back();

    cout << "After Removing Front and Back: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Insert at a specific position (2nd position in this case)
    auto it = linkedList.begin();
    advance(it, 1); // Move iterator to 2nd position
    linkedList.insert(it, 25);

    cout << "After Insertion at 2nd Position: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Remove a specific element
    linkedList.remove(25);

    cout << "After Removing Element 25: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Reverse the linked list
    linkedList.reverse();
    cout << "Reversed List: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Sort the linked list
    linkedList.push_back(15); // Adding extra element to see sorting
    linkedList.sort();
    cout << "Sorted List: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
