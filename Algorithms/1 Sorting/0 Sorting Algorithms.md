# Sorting Algorithms Overview

Sorting algorithms are essential in computer science and programming, as they help arrange data in a specific order, such as ascending or descending. Efficient sorting can significantly reduce the time complexity of searching and processing tasks. Sorting algorithms can be divided into various types based on their logic, complexity, and applications. Some popular sorting algorithms include:

- Bubble Sort: Simple, but inefficient for large datasets.
- Selection Sort: Finds the minimum element and places it at the beginning.
- Insertion Sort: Builds a sorted list one element at a time.
- Merge Sort: Divides the array into smaller parts and merges them in sorted order.
- Quick Sort: Selects a pivot and partitions the array into two parts.
- Heap Sort: Builds a heap and repeatedly extracts the largest element.
- Radix Sort: Sorts numbers digit by digit.
- Bucket Sort: Distributes elements into buckets and sorts them individually.

## 6. Heap Sort

Heap sort uses a binary heap data structure to sort the array. It first builds a max-heap and then repeatedly extracts the maximum element to place it in the correct position.

- **Time Complexity**: \(O(n \log n)\) in all cases.
- **Space Complexity**: \(O(1)\) (In-place).

### Pros:
- Guarantees \(O(n \log n)\) time complexity.
- In-place sorting.
- More predictable performance compared to quicksort.

### Cons:
- Unstable (does not maintain the relative order of equal elements).
- Slower in practice than quicksort due to constant factors.
- More complex to implement compared to simpler algorithms.

---

## 7. Radix Sort

Radix sort sorts numbers digit by digit, starting from the least significant to the most significant digit. It’s a non-comparative sorting algorithm.

- **Time Complexity**: \(O(nk)\), where \(n\) is the number of elements, and \(k\) is the number of digits in the largest number.
- **Space Complexity**: \(O(n+k)\) (requires extra memory).

### Pros:
- Fast when sorting integers with a small number of digits.
- Does not involve comparisons.
- Stable sorting algorithm.

### Cons:
- Requires additional space.
- Not suitable for sorting arbitrary types like floating-point numbers or complex data structures.
- Can be slower than comparison-based algorithms when numbers have a large number of digits.

---

## 8. Bucket Sort

Bucket sort distributes elements into buckets, sorts each bucket individually (using another sorting algorithm or recursively), and then combines them.

- **Time Complexity**: \(O(n+k)\), where \(n\) is the number of elements, and \(k\) is the number of buckets.
- **Space Complexity**: \(O(n+k)\) (requires additional space for buckets).

### Pros:
- Efficient for sorting a small range of values.
- Can achieve linear time complexity \(O(n)\) in the best-case scenario.
- Useful for data uniformly distributed over a range.

### Cons:
- Requires additional memory for the buckets.
- Performance depends heavily on how the elements are distributed among the buckets.
- Not suitable for large datasets with non-uniform distributions.



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
