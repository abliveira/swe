#include <iostream>
using namespace std;

/* 
 * This implementation of the Selection Sort algorithm uses functions for better code organization
 * and modularity. Unlike a non-functional approach where the sorting logic would be written directly 
 * in the main function, this structure separates concerns, allowing for easier maintenance and 
 * reusability of the sorting logic and array printing.
 */

// Swap function to exchange two elements in the array
void swap(int *a, int *b) {
    int temp = *a;  // Store value of 'a' in temp
    *a = *b;        // Assign value of 'b' to 'a'
    *b = temp;      // Assign stored 'temp' (original 'a') to 'b'
}

// Selection Sort function
void selectionSort(int arr[], int size) {
    // Outer loop to iterate over the array
    for (int passIdx = 0; passIdx < size - 1; passIdx++) {
        int minIdx = passIdx; // Assume the first element is the minimum

        // Inner loop to find the smallest element in the remaining array
        for (int currentIdx = passIdx + 1; currentIdx < size; currentIdx++) {
            // If the current element is smaller, update the min index
            if (arr[currentIdx] < arr[minIdx]) {
                minIdx = currentIdx;
            }
        }

        // Swap the smallest element found with the element at index 'passIdx'
        swap(&arr[minIdx], &arr[passIdx]);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Print each element of the array
    }
    cout << endl;  // Print a new line for better readability
}

// Main function
int main() {
    // Array to be sorted
    int arr[] = {5, 2, 42, 6, 1, 3, 2}; // Sample array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    selectionSort(arr, size);  // Call the selection sort function to sort the array
    printArray(arr, size);      // Print the sorted array

    return 0;  // End of program
}
