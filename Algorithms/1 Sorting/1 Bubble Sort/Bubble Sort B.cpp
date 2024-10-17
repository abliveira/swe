#include <iostream>
using namespace std;

/* 
    This new C++ code improves upon the previous implementation by using a dedicated swap function, 
    implementing an optimization to reduce unnecessary passes through the array, separating functionality 
    into distinct functions for clarity, and enhancing modularity.

    References:
        SoloLearn / Aaron Sarkissian

*/

void swap(int *firstElement, int *secondElement) {
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void bubbleSort(int arr[], int size) {
    bool swapped; // Flag to track if a swap has occurred
    // Outer loop for each pass through the array
    for (int passIndex = 0; passIndex < size - 1; passIndex++) {
        swapped = false; // Initialize the swapped flag to false for each pass
        // Inner loop to compare adjacent elements
        for (int currentIndex = 0; currentIndex < size - passIndex - 1; currentIndex++) { 
            // Compare adjacent elements
            if (arr[currentIndex] > arr[currentIndex + 1]) {
                swap(&arr[currentIndex], &arr[currentIndex + 1]); // Use swap function to swap elements
                swapped = true; // Set swapped to true as a swap occurred
            }
        }
        // If no swaps occurred, the array is already sorted
        if (!swapped)
            break; // Exit the loop if the array is sorted
    }
}

void printArray(int arr[], int size) {
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}

int main() {

    int arr[] = {1, 5, 3, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}
