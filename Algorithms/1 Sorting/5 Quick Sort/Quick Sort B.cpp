#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(int arr[], int start, int end) {
    // Choose pivot (last element in the range)
    int pivot = arr[end];
    int pivotIndex = start - 1;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }

    // Place pivot in its final position
    swap(arr[pivotIndex + 1], arr[end]);
    return pivotIndex + 1;
}

// QuickSort function that utilizes the Python-style partition
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // Partition array and get the pivot index
        int pivotIndex = partition(arr, start, end);

        // Recursively apply QuickSort to subarrays
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initialize array and seed random number generator
    int arr[] = {31, 4, 88, 1, 4, 2, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform QuickSort
    quickSort(arr, 0, size - 1);

    // Output sorted array
    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
