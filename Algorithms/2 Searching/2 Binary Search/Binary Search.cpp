#include <iostream>
using namespace std;

/* 
    Binary Search is an efficient algorithm for locating the position of a target value 
    within a sorted array. It follows a divide-and-conquer approach, repeatedly halving 
    the search range until the target is found or the range becomes empty. The algorithm 
    is called binary search because it divides the array into two halves at each step, 
    with the target being located in either the left or right half.

    Comparison with Linear Search:
        - In linear search, the worst-case scenario requires checking each element, 
          resulting in 1000 comparisons for an array of size 1000.
        - In binary search, the worst-case scenario involves about 10 comparisons, 
          because the range is halved with each step (\( \log_2(1000) \approx 10 \)).
        - This makes binary search **100 times faster** than linear search for searching 
          a sorted array of size 1000. However, binary search requires the array to be 
          sorted beforehand.

    Time Complexity:
        - O(log n), as the search range is halved at each step.

    Space Complexity:
        - O(1) for the iterative implementation, or O(log n) for the recursive implementation.

    Pros:
        - Efficient with a time complexity of O(log n).
        - Can be implemented both iteratively and recursively.
        - In-place algorithm (does not require additional space).

    Cons:
        - Only works on sorted arrays.
        - Not as efficient for small datasets when compared to linear search.

    The algorithm works as follows:
        1. The array must be sorted for binary search to work correctly.
        2. It starts by comparing the target value with the middle element of the array.
        3. If the target matches the middle element, the index is returned.
        4. If the target is smaller than the middle element, the search continues in the left half.
        5. If the target is larger than the middle element, the search continues in the right half.
        6. This process is repeated on the remaining subarray until the target is found 
           or the subarray becomes empty.

    Example:
        For the array [2, 5, 16, 18, 24, 42] and a target value of 24:
        1. The middle element is 16. Since 24 > 16, it narrows the search to the right subarray: [18, 24, 42].
        2. The middle element is 24. Since 24 == 24, it returns the index of 24, which is 4.
*/

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid index

        if (arr[mid] == target) {
            return mid; // Target found, return the index
        }
        else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target); // Search the right half
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target); // Search the left half
        }
    }
    return -1; // Target not found
}

int main() {
    // Sorted array for binary search
    int arr[] = {1, 2, 4, 6, 8, 12, 16, 18, 24, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Define the target value to search for
    int target = 18;
    
    // Perform Recursive Binary Search
    int resultRecursive = binarySearchRecursive(arr, 0, size - 1, target);
    if (resultRecursive != -1) {
        cout << "Recursive Binary Search: Found at index " << resultRecursive << endl;
    } else {
        cout << "Recursive Binary Search: Not found in the array." << endl;
    }

    return 0;
}