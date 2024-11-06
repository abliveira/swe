'''
QuickSort picks an element as pivot and partitions the given list around it.
We will choose our pivot randomly.
We will implement the quicksort function recursively. During each iteration our function will partition the array based on the randomly picked pivot:

So, the quicksort function is taking the list of elements, choosing a random pivot point, partition the array based on that pivot, and recursively call it for both partitions until the list is sorted.
The partition function is an important part of this implementation.

References:
    SoloLearn / Tiagran Harutyunyan
'''

from random import randint

def quicksort(lst, left, right):
    """
    Sorts the list in place using the QuickSort algorithm, which is a
    divide-and-conquer approach with recursive partitioning around a pivot.
    """
    if left < right:
        # Choose a random pivot and swap it with the last element for partitioning
        pivot_index = randint(left, right)
        lst[right], lst[pivot_index] = lst[pivot_index], lst[right]
        
        # Partition the list around the pivot
        partition_index = partition(lst, left, right)
        
        # Recursively apply QuickSort to the left and right sublists
        quicksort(lst, left, partition_index - 1)
        quicksort(lst, partition_index + 1, right)

def partition(lst, left, right):
    """
    Partitions the list around a pivot, placing all elements less than
    the pivot to the left and all elements greater to the right.
    """
    pivot_position = left - 1  # Tracks the position of the smaller elements
    pivot_value = lst[right]  # The pivot value is the last element in the range
    
    for current in range(left, right):
        # Compare each element with the pivot value
        if lst[current] < pivot_value:
            pivot_position += 1
            # Swap current element with element at pivot_position
            lst[pivot_position], lst[current] = lst[current], lst[pivot_position]
    
    # Swap the pivot value to its correct position
    lst[pivot_position + 1], lst[right] = lst[right], lst[pivot_position + 1]
    
    # Return the index of the pivot after partitioning
    return pivot_position + 1

def main():
    numbers = [31, 4, 88, 1, 4, 2, 42]
    
    print("Original list:", numbers)
    quicksort(numbers, 0, len(numbers) - 1)
    print("Sorted list:", numbers)

if __name__ == "__main__":
    main()
