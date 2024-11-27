#include <iostream>
using namespace std;

/* 
    Ternary Search is a divide-and-conquer algorithm used for searching a target value 
    in a sorted array. Unlike Binary Search, which divides the array into two parts, 
    Ternary Search splits the array into three parts by using two midpoints. The algorithm 
    recursively narrows down the search range by eliminating two-thirds of the array 
    in each step.

    Time Complexity:
        - O(log_3 n), where the array is divided into three parts at each step.

    Space Complexity:
        - O(1) for the iterative implementation or O(log n) for the recursive implementation.

    Pros:
        - More efficient than binary search in terms of reducing the search space faster.
        - Works on sorted arrays.

    Cons:
        - Slightly more complex compared to binary search.
        - Still requires the array to be sorted.

    The algorithm works as follows:
        1. The array must be sorted for ternary search to work correctly.
        2. Divide the array into three parts by computing two midpoints, `mid1` and `mid2`.
        3. Compare the target value with `mid1` and `mid2`.
        4. If the target is equal to `mid1`, return `mid1`.
        5. If the target is equal to `mid2`, return `mid2`.
        6. If the target is less than `mid1`, search the left third of the array.
        7. If the target is greater than `mid2`, search the right third of the array.
        8. If the target is between `mid1` and `mid2`, search the middle third of the array.
        9. Repeat until the target is found or the array range becomes empty.
*/

// Recursive Ternary Search
int ternarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3; // Calculate first mid
        int mid2 = right - (right - left) / 3; // Calculate second mid

        if (arr[mid1] == target) {
            return mid1; // Target found at mid1
        }
        if (arr[mid2] == target) {
            return mid2; // Target found at mid2
        }

        if (target < arr[mid1]) {
            return ternarySearchRecursive(arr, left, mid1 - 1, target); // Search left part
        }
        else if (target > arr[mid2]) {
            return ternarySearchRecursive(arr, mid2 + 1, right, target); // Search right part
        }
        else {
            return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, target); // Search middle part
        }
    }
    return -1; // Target not found
}

int main() {
    // Sorted array for ternary search
    int arr[] = {1, 2, 4, 6, 8, 12, 16, 18, 24, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Define the target value to search for
    int target = 18;

    // Perform Recursive Ternary Search
    int resultRecursive = ternarySearchRecursive(arr, 0, size - 1, target);
    if (resultRecursive != -1) {
        cout << "Recursive Ternary Search: Found at index " << resultRecursive << endl;
    } else {
        cout << "Recursive Ternary Search: Not found in the array." << endl;
    }

    return 0;
}
