#include <iostream>
using namespace std;

/*
    Insertion sort works by building a sorted portion of the array one element at a time. 
    It repeatedly takes the next unsorted element and inserts it into the correct position within the sorted portion.

    Insertion Sort is efficient for small datasets or nearly sorted arrays and is used in practice in certain situations due to its simplicity and performance in those scenarios.

    Time Complexity:
    - Worst/Average: O(n^2)
    - Best: O(n) when the array is already sorted
    
    Space Complexity:
    - O(1) (In-place)
    
    Pros:
    - Simple and easy to understand.
    - Efficient for small datasets or nearly sorted arrays.
    - In-place algorithm (requires no extra space).
    - Stable (maintains the relative order of equal elements).
    - Linear time complexity for nearly sorted arrays.

    Cons:
    - Inefficient for large datasets due to O(n^2) time complexity.
*/

int main() {
    int arr[] = {1, 5, 3, 2, 4}; // Sample array to be sorted
    int size = sizeof(arr) / sizeof(int); // Number of elements in the array

    // Perform Insertion Sort
    for (int i = 1; i < size; i++) {
        int key = arr[i]; // Take the current element to be inserted
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }

    /* Example: Let's take the following array: [3, 1, 5, 2]
    First iteration:
    Step 1: Compare arr[1] (1) with arr[0] (3), shift 3 to the right, and insert 1.
            New array: [1, 3, 5, 2]
    
    Second iteration:
    Step 1: Compare arr[2] (5) with the sorted portion [1, 3], no shifting is needed.
            Array remains: [1, 3, 5, 2]
    
    Third iteration:
    Step 1: Compare arr[3] (2) with the sorted portion [1, 3, 5], shift 5 and 3 to the right and insert 2.
            Final array: [1, 2, 3, 5]
    */

    // Output the sorted array
    cout << "After Sorting: ";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}
