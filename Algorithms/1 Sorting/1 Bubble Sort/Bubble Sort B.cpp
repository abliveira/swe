#include <iostream>
using namespace std;

/* 

    This new C++ code improves upon the previous implementation by using a dedicated swap function, implementing an optimization to reduce unnecessary passes through the array, separating functionality into distinct functions for clarity, and enhancing modularity

References:
    SoloLearn / Aaron Sarkissian

*/

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    bool swapped; // Flag to track if a swap has occurred
    for (int i = 0; i < n - 1; i++) {
        swapped = false; // Initialize the swapped flag to false for each pass
        for (int j = 0; j < n - i - 1; j++) { // Reduced range for inner loop
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); // Use swap function to swap elements
                swapped = true; // Set swapped to true as a swap occurred and sorting process can end early
            }
        }
        // If no swaps occurred, the array is already sorted
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; // Print each element of the array
}

int main() {

    int arr[] = {1, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}
