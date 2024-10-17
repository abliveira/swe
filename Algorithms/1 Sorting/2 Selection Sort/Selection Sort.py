# Selection Sort Algorithm

"""
Selection sort is an in-place comparison sorting algorithm.
It divides the input array into a sorted and unsorted part, and repeatedly selects
the minimum element from the unsorted part and swaps it with the first unsorted element.

- Time Complexity: O(n^2) in all cases
- Space Complexity: O(1) (In-place)

### Explanation of the First Iteration with Array: [3, 1, 5, 2]
Step 1: Find the minimum in the array [3, 1, 5, 2], which is 1.
        Swap it with the first element.
        New array: [1, 3, 5, 2]

Step 2: Find the minimum in the remaining array [3, 5, 2], which is 2.
        Swap it with the second element.
        New array: [1, 2, 5, 3]

Step 3: Find the minimum in the remaining array [5, 3], which is 3.
        Swap it with the third element.
        New array: [1, 2, 3, 5]

The process continues until the array is fully sorted.
"""

def selection_sort(arr):
    size = len(arr)  # Get number of elements in the array

    print("Before Sorting:", arr)  # Print the original array

    # Outer loop to go through the array
    for pass_idx in range(size):
        # Assume the first unsorted element is the minimum
        min_idx = pass_idx
        
        # Inner loop to find the minimum element in the unsorted part
        for current_idx in range(pass_idx + 1, size):
            if arr[current_idx] < arr[min_idx]:
                min_idx = current_idx  # Update the index of the minimum element

        # Swap the found minimum element with the first unsorted element
        arr[pass_idx], arr[min_idx] = arr[min_idx], arr[pass_idx]

    print("After Sorting:", arr)  # Print the sorted array

# Example usage
array = [3, 1, 5, 2]  # Initialize array
selection_sort(array)
