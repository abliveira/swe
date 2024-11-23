# Sorting Algorithms Overview

Sorting algorithms are essential in computer science and programming, as they help arrange data in a specific order, such as ascending or descending. Efficient sorting can significantly reduce the time complexity of searching and processing tasks. Sorting algorithms can be divided into various types based on their logic, complexity, and applications.

## Summary Table of Sorting Algorithms

| **Algorithm**      | **Explanation**                                                                 | **Pros**                                                   | **Cons**                                                                 |
|--------------------|---------------------------------------------------------------------------------|-------------------------------------------------------------|--------------------------------------------------------------------------|
| **Bubble Sort**     | Repeatedly swaps adjacent elements if they are in the wrong order.              | Simple, In-place, Stable                                     | Inefficient \(O(n^2)\) for large datasets                                |
| **Selection Sort**  | Selects the smallest (or largest) element and places it at the beginning.       | Easy to implement, In-place                                  | Inefficient \(O(n^2)\), More swaps, Unstable                             |
| **Insertion Sort**  | Inserts elements one by one into their correct position in the sorted portion.  | Efficient for small/partially sorted arrays, Stable          | \(O(n^2)\) for large datasets                                            |
| **Merge Sort**      | Divides the array into smaller subarrays, sorts them, and merges them together. | \(O(n \log n)\), Stable, Performs well on large datasets     | Requires extra memory, Slower on small datasets                          |
| **Quick Sort**      | Selects a pivot, partitions the array around it, and sorts the partitions.      | \(O(n \log n)\) on average, In-place, Efficient              | Worst-case \(O(n^2)\), Unstable                                          |
| **Heap Sort**       | Uses a binary heap to extract max elements and build a sorted array.            | \(O(n \log n)\), In-place, Predictable performance           | Unstable, Slower than quicksort in practice                              |
| **Radix Sort**      | Sorts numbers digit by digit, starting from the least significant digit.        | Linear time for small range integers, Stable                 | Requires extra memory, Limited to certain data types                     |
| **Bucket Sort**     | Distributes elements into buckets, sorts each bucket, and merges them.          | Linear time for uniformly distributed data                   | Requires extra memory, Not efficient for non-uniform data                |
