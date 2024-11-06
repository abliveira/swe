#include <iostream>
using namespace std;

/*
    Merge Sort is a divide and conquer algorithm that recursively splits an array into two halves, sorts each half, and then merges the sorted halves back together. The "divide and conquer" name reflects this process of dividing the array into smaller parts and conquering by merging them back in sorted order.

    By utilizing recursion, each merge step requires only linear comparisons between the smallest remaining elements in the pre-sorted subarrays, ensuring O(n log n) efficiency by reducing redundant comparisons and achieving high sorting speeds.

    Time Complexity:
        - O(n log n) in all cases (worst, average, and best)

    Space Complexity:
        - O(n) (requires auxiliary space for merging)
    
    Pros:
        - Stable sorting algorithm
        - Performs well on large datasets
        - Suitable for sorting linked lists and external data
    
    Cons:
        - Requires additional space (O(n)), which can be a downside for large datasets
        - Slower for small datasets compared to algorithms like quicksort

    Example: [31, 4, 88, 1, 4, 2, 42]

        Step 1: Divide the array in half
            - First split: [31, 4, 88, 1], [4, 2, 42]

        Step 2: Recursively divide each half until each subarray has only one element

            - Left half [31, 4, 88, 1]
                - Split into: [31, 4], [88, 1]
                - Further split: [31], [4], [88], [1]
            
            - Right half [4, 2, 42]
                - Split into: [4, 2], [42]
                - Further split: [4], [2], [42]

        Step 3: Begin merging sorted subarrays back together

            - Left half:
                - Merge [31] and [4] → sorted as [4, 31]
                - Merge [88] and [1] → sorted as [1, 88]
                - Merge [4, 31] and [1, 88] → sorted as [1, 4, 31, 88]

            - Right half:
                - Merge [4] and [2] → sorted as [2, 4]
                - Merge [2, 4] and [42] → sorted as [2, 4, 42]

        Step 4: Final merge of both sorted halves
            - Merge [1, 4, 31, 88] and [2, 4, 42], resulting in the fully sorted array: [1, 2, 4, 4, 31, 42, 88]

        Final sorted array: [1, 2, 4, 4, 31, 42, 88]
*/

// Merge two halves into a sorted array
void mergeHalves(int* arr, int left, int mid, int right) {
    int leftIndex = left;
    int rightIndex = mid + 1;
    int mergedIndex = 0;

    // Create temporary array to hold merged elements
    int mergedArray[right - left + 1];

    // Merge the two halves into mergedArray[]
    while (leftIndex <= mid && rightIndex <= right) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            mergedArray[mergedIndex++] = arr[leftIndex++];
        } else {
            mergedArray[mergedIndex++] = arr[rightIndex++];
        }
    }

    // Copy remaining elements from left half
    while (leftIndex <= mid) {
        mergedArray[mergedIndex++] = arr[leftIndex++];
    }

    // Copy remaining elements from right half
    while (rightIndex <= right) {
        mergedArray[mergedIndex++] = arr[rightIndex++];
    }

    // Copy sorted elements back into the original array
    for (int i = left, j = 0; i <= right; i++, j++) {
        arr[i] = mergedArray[j];
    }
}

// Recursive merge sort function
void mergeSortRecursive(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2; // Find the midpoint

        // Recursively sort the left and right halves
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        // Merge the sorted halves
        mergeHalves(arr, left, mid, right);
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {31, 4, 88, 1, 4, 2, 42};  // Sample array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    mergeSortRecursive(arr, 0, size - 1);  // Call merge sort on the array

    cout << "After Sorting: ";
    printArray(arr, size);  // Output the sorted array

    return 0;
}
