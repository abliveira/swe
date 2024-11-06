#include <iostream>
using namespace std;

/*

    Selection sort divides the array into a sorted and an unsorted part. It repeatedly selects the smallest (or largest) element from the unsorted portion and places it at the beginning of the sorted section.

    Selection Sort gets its name from the method of selecting the smallest element from the unsorted portion of the array and moving it to the beginning of the sorted portion.

    The algorithm is efficient for smaller lists, but very inefficient for larger lists. Also, it does not require any additional storage space, as it operates in-place.

    Time Complexity:
        - Worst/Average/Best: O(n^2)
    
    Space Complexity:
        - O(1) (In-place)
    
    Pros:
        - Simple and easy to understand.
        - In-place algorithm (requires no extra space).
        - Useful when memory writes are costly, as it does the minimum number of swaps.
        - Works well for small datasets.

    Cons:
        - Inefficient for large datasets due to O(n^2) time complexity.
        - More swaps than other quadratic algorithms (like insertion sort).
        - Unstable (does not maintain relative order of equal elements).

*/

int main() {

    int arr[] = {1, 5, 3, 2, 4}; // Sample array to be sorted
    int size = sizeof(arr) / sizeof(int); // Number of elements in the array

    // Perform Selection Sort
    for (int current = 0; current < size - 1; current++) { // Outer loop for each position in the array
        // Find the minimum element in the unsorted part of the array
        int minIndex = current; // Assume the first unsorted element is the minimum
        for (int next = current + 1; next < size; next++) { // Inner loop to find the smallest element
            if (arr[next] < arr[minIndex]) { // If a smaller element is found, update minIndex
                minIndex = next;
            }
        }
        // Swap the found minimum element with the first unsorted element
        int temp = arr[current];
        arr[current] = arr[minIndex];
        arr[minIndex] = temp;
    }

    /* Example: Let's take the following array: [3, 1, 5, 2]
    First iteration:
    Step 1: Find the minimum element from index 0 to 3.
            The minimum is 1 at index 1, so swap arr[0] and arr[1].
            New array: [1, 3, 5, 2]
    
    Second iteration:
    Step 1: Find the minimum element from index 1 to 3.
            The minimum is 2 at index 3, so swap arr[1] and arr[3].
            New array: [1, 2, 5, 3]
    
    Third iteration:
    Step 1: Find the minimum element from index 2 to 3.
            The minimum is 3 at index 3, so swap arr[2] and arr[3].
            Final array: [1, 2, 3, 5]
    */

    // Output the sorted array
    cout << "After Sorting: ";
    for (int current = 0; current < size; current++) {
        cout << " " << arr[current];
    }
    cout << endl;

    return 0;
}