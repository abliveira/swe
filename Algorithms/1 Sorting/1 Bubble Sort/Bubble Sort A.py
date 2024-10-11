# Bubble Sort Algorithm

"""
Bubble sort is a basic comparison-based algorithm that repeatedly steps through the list,
compares adjacent elements, and swaps them if they are in the wrong order.

- Time Complexity: Worst/Average O(n^2), Best O(n)
- Space Complexity: O(1) (In-place)

### Explanation of the First Iteration with Array: [3, 1, 5, 2]
Step 1: Compare arr[0] (3) and arr[1] (1)
         Since 3 > 1, swap them.
         New array: [1, 3, 5, 2]

Step 2: Compare arr[1] (3) and arr[2] (5)
         Since 3 < 5, do not swap.
         Array remains: [1, 3, 5, 2]

Step 3: Compare arr[2] (5) and arr[3] (2)
         Since 5 > 2, swap them.
         New array: [1, 3, 2, 5]

After the first iteration, the array looks like this: [1, 3, 2, 5]
Now we need to start the second iteration:
Step 1: Compare arr[0] (1) and arr[1] (3)
         No swap: [1, 3, 2, 5]
Step 2: Compare arr[1] (3) and arr[2] (2)
         Swap: [1, 2, 3, 5]
Step 3: Compare arr[2] (3) and arr[3] (5)
         No swap: [1, 2, 3, 5]

The process continues until the array is fully sorted.
"""

def bubble_sort(arr):
    n = len(arr)  # Get number of elements in array

    print("Before Sorting:", arr)  # Print original array

    # Outer loop for each pass through the array
    for i in range(n):
        # Inner loop for comparing adjacent elements
        for j in range(n - 1):
            # Compare adjacent elements and swap if in the wrong order
            if arr[j] > arr[j + 1]:
                # Space complexity O(1) for temp variable
                temp = arr[j]  # Use a temporary variable for swapping
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    print("After Sorting:", arr)  # Print sorted array

# Example usage
array = [3, 1, 5, 2]  # Initialize array
bubble_sort(array)
