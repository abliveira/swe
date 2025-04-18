#include <iostream>
using namespace std;

/* 

    Bubble sort is a basic comparison-based algorithm that repeatedly steps through the list,
    compares adjacent elements, and swaps them if they are in the wrong order.

    The algorithm is called Bubble Sort because it repeatedly steps through the list, "bubbling" larger elements to the top (end of the list) with each pass, similar to bubbles rising to the surface of water.

    Time Complexity
        - Worst (where all elements need to be swapped) / Average: O(n^2)
        - Best (no elements to be swapped): O(n)
    
    Space Complexity
        - O(1) (In-place)

    Pros:
        - Simple to understand and implement.
        - In-place algorithm (requires no extra space).
        - Efficient for small datasets or nearly sorted arrays.

    Cons:
        - Very inefficient for large datasets due to O(n^2) time complexity.
        - Performs poorly when the list is in reverse order.
        - Redundant comparisons and swaps make it slow compared to more advanced algorithms.

*/

int main() {

    int arr[] = {1, 5, 3, 2, 4}; // Sample array to be sorted
    int size = sizeof(arr) / sizeof(int); // Number of elements in the array

    // Perform Bubble Sort

    for (int passIdx = 0; passIdx < size; passIdx++) { // Outer loop for each pass through the array
        // The outer loop runs 'size' times, contributing to O(n) in the best case
        // and O(n^2) in the average and worst cases due to nested iterations.

        for (int currentIdx = 0; currentIdx < size - 1; currentIdx++) { // Inner loop for comparing adjacent elements
            // The inner loop also runs 'size-1' times for each iteration of the outer loop.
            // Together, they create a nested structure that results in O(n^2) time complexity.

            if (arr[currentIdx] > arr[currentIdx + 1]) { // Swap if the current element is greater than the next
                int temp = arr[currentIdx]; // Temporary variable for swapping (O(1) space)
                arr[currentIdx] = arr[currentIdx + 1];
                arr[currentIdx + 1] = temp;
            }
        }
    }

    /* Example of Bubble Sort Execution:
    
    Let's take the following array: [3, 1, 5, 2]
    First iteration:
    Step 1: Compare arr[0] (3) and arr[1] (1)
            Since 3 > 1, swap them.
            New array: [1, 3, 5, 2]

    Step 2: Compare arr[1] (3) and arr[2] (5)
            Since 3 < 5, no swap needed.
            Array remains: [1, 3, 5, 2]

    Step 3: Compare arr[2] (5) and arr[3] (2)
            Since 5 > 2, swap them.
            New array: [1, 3, 2, 5]

    After the first iteration, the array looks like this: [1, 3, 2, 5]

    Second iteration:
    Step 1: Compare arr[0] (1) and arr[1] (3)
            No swap needed: [1, 3, 2, 5]
    Step 2: Compare arr[1] (3) and arr[2] (2)
            Swap: [1, 2, 3, 5]
    Step 3: Compare arr[2] (3) and arr[3] (5)
            No swap needed: [1, 2, 3, 5]

    The process continues until the array is fully sorted. */

    // Output the sorted array
    cout << "After Sorting: ";
    for (int passIdx = 0; passIdx < size; passIdx++) {
        cout << " " << arr[passIdx]; // Print each element of the sorted array
    }
    cout << endl;

    return 0;
}
