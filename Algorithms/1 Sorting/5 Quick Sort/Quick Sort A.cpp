#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    QuickSort is a divide and conquer algorithm that efficiently sorts an array by recursively partitioning it into smaller subarrays. 
    The "divide and conquer" approach involves selecting a pivot element and dividing the array into two parts: one containing elements less than the pivot 
    and the other containing elements greater than the pivot. This process continues recursively until the subarrays are small enough to be sorted easily.

    The choice of pivot is crucial, and QuickSort implementations may vary in their method of selecting the pivot—options include using the first element, 
    the last element, the median, or a randomly selected element. 

    After partitioning, QuickSort is called recursively on the two resulting subarrays. The result is a fully sorted array when all recursive calls are completed.

    Merge Sort and QuickSort both utilize the divide and conquer strategy, but they sort differently. Merge Sort divides the array into halves, sorts each half, and merges them back together, ensuring stability. In contrast, QuickSort partitions the array around a pivot and sorts in place, often leading to faster performance but potentially instability depending on the pivot choice. While Merge Sort consistently achieves O(n log n) time complexity, QuickSort averages O(n log n) but can degrade to O(n²) in the worst case.

    Time Complexity:
        - O(n log n) on average
        - O(n^2) in the worst case (when the smallest or largest element is consistently chosen as the pivot)

    Space Complexity:
        - O(log n) for the call stack due to recursion

    Pros:
        - Operates in-place, requiring minimal additional storage
        - Generally faster than other O(n log n) algorithms due to its efficient cache performance
        - Can be optimized with different pivot selection methods

    Cons:
        - Performance can degrade significantly with poor pivot selection
        - Not stable by default (equal elements may not maintain their original order)

    Example: [2, 0, 7, 4, 3]
        
        Step 1: Choose the pivot
            - Select 3 (last element) as the pivot.
        
        Step 2: Partition the array
            - After partitioning, we get: [2, 0] (3) [7, 4]
        
        Step 3: Recursively apply QuickSort to the left and right halves
            - Left half [2, 0]:
                - Choose 0 as the pivot: [ (0) [2] ] 
            - Right half [7, 4]:
                - Choose 4 as the pivot: [ (4) [7] ]

        Final sorted sequence: [ (0) [2] ] (3) [ (4) [7] ] → [0, 2, 3, 4, 7]
        
    References:
        SoloLearn / Aaron Sarkissian
*/

void QuickSort(int *arr, int left, int right) {
    int leftIndex = left;
    int rightIndex = right - 1;
    int size = right - left;

    // The QuickSort function is taking the array of elements, choosing a random pivot point, creates two subarrays based on that pivot and recursively call it till all elements become sorted
    
    if(size > 1) {
        int pivot = arr[rand() % size + leftIndex];

        // Partitioning the array into two subarrays based on the pivot
        while (leftIndex < rightIndex) {
            // Find elements greater than the pivot from the right side
            while (arr[rightIndex] > pivot && rightIndex > leftIndex) {
                rightIndex--;
            }
            // Find elements smaller than the pivot from the left side
            while (arr[leftIndex] < pivot && leftIndex <= rightIndex) {
                leftIndex++;
            }

            // If leftIndex is still less than rightIndex, swap the elements
            if (leftIndex < rightIndex) {
                swap(arr[leftIndex], arr[rightIndex]);
                leftIndex++; // Move leftIndex forward
            }
        }

        // Recursively sort the two partitions
        QuickSort(arr, left, leftIndex);      // Left partition
        QuickSort(arr, rightIndex, right);    // Right partition
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    // During each iteration the function picks a random pivot and partition the array based on it
    int arr[] = {31, 4, 88, 1, 4, 2, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    QuickSort(arr, 0, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}