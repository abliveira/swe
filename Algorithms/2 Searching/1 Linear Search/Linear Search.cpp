#include <iostream>
using namespace std;

/* 
    Linear search is a simple search algorithm. It sequentially checks each element
    in the list until a match is found or the end of the list is reached. This algorithm 
    works on unsorted lists but is generally less efficient compared to other search 
    algorithms like binary search.

    Time Complexity: 
        - Best O(1)
        - Worst O(n)

    Space Complexity:
        - O(1) (In-place)

    Pros:
        - Simple to implement.
        - Works on unsorted lists or arrays.
        - In-place algorithm (requires no extra space).

    Cons:
        - Inefficient for large datasets with O(n) time complexity.
        - Doesn’t take advantage of the sorted structure of the data.
*/

int search(int arr[], int size, int target) {
    // Iterate through the array and look for the target value
    for (int k = 0; k < size; k++) {
        if (arr[k] == target) {
            return k; // Return the index if the value is found
        }
    }
    return -1; // Return -1 if the value is not found
}

int main() {
    int arr[] = {5, 2, 42, 6, 1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 42;

    int result = search(arr, size, target);
    if (result != -1) {
        cout << "Found at index: " << result << endl;
    } else {
        cout << "Not found in the array." << endl;
    }

    return 0;
}
