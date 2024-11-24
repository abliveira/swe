#include <iostream>
using namespace std;

/* 
    An array is a collection of elements, all of the same type, stored in contiguous memory locations. 
    The elements can be accessed using an index, with the first element typically at index 0.

    Use case:
        - Arrays are useful for storing a fixed-size sequence of elements and are especially efficient for accessing elements via indices.


    Time Complexity:
        - Access: O(1), as elements can be accessed directly via indices.
        - Search: O(n), as the entire array may need to be searched for an element.
        - Insert/Remove: O(n), since elements may need to be shifted when inserting or removing elements.

    Space Complexity:
        - O(n), as the size of the array is fixed at the time of allocation and it stores n elements.

    Pros:
        - Efficient for accessing elements via indices.
        - Simple to use and implement.
        - Fixed-size storage is ideal for certain applications.

    Cons:
        - Size is fixed, and cannot be changed dynamically (unless using dynamic arrays like `std::vector`).
        - Insertion and deletion are costly when elements need to be shifted.

*/


int main() {

    // Create an array of integers
    int arr[] = {10, 20, 30, 40, 50};
    
    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print all elements of the array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Access individual elements using indices
    cout << "Element at index 0: " << arr[0] << endl;
    cout << "Element at index 2: " << arr[2] << endl;

    // Modify an element of the array
    arr[3] = 100;
    cout << "Array after modification: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
