'''
    In Python, we have two primary ways to store collections of data: arrays and lists. Lists are a default data structure in Python, while array must be imported from an external module. Both are used to store ordered sequences of elements, but they have distinct characteristics.

    List
        A Python list is a dynamic array that can hold elements of different types and can be resized at runtime. It is the most commonly used data structure for handling sequences of elements.

    Array (from array module)
        A Python array, on the other hand, is more like a traditional array in other languages like C or Java. It can only hold elements of the same type and is more memory efficient when working with large collections of numeric data.
    
    Time Complexity:
        - List 
            - Access: O(1) 
            - Search: O(n)
            - Insert/Remove: O(n)
        - Array (from array module)
            - Access: O(1)
            - Search: O(n)
            - Insert/Remove: O(n) (but more efficient than lists for numeric data)

    Space Complexity:
        - List 
            - O(n), dynamically resizes and stores elements of any type.
        - Array
            - O(n), fixed size based on the type of elements, and stores homogeneous data.

    Pros:
        - List
            - Flexible, can hold mixed data types (e.g., integers, strings, objects).
            - Dynamically resizable.
            - Easy to use and most commonly used in Python.
        - Array
            - More memory efficient for large datasets, especially when dealing with numbers.
            - Ensures homogeneous data types, which may be beneficial for performance when working with large numerical data.

    Cons:
        - List
            - Can be less memory efficient when storing large collections of similar elements (e.g., numerical data).
            - More overhead compared to arrays.
        - Array
            - Can only store elements of the same type.
            - Not as flexible as lists for mixed-type data storage.
'''

import array

# Create a list of integers
list_example = [10, 20, 30, 40, 50]

# Create an array of integers (only numeric types allowed)
array_example = array.array('i', [10, 20, 30, 40, 50])  # 'i' represents an integer type

# Calculate the size of the list and array
size_list = len(list_example)
size_array = len(array_example)

# Print all elements of the list
print("List elements:", end=" ")
for i in range(size_list):
    print(list_example[i], end=" ")
print()

# Print all elements of the array
print("Array elements:", end=" ")
for i in range(size_array):
    print(array_example[i], end=" ")
print()

# Access individual elements using indices
print(f"Element at index 0 in list: {list_example[0]}")
print(f"Element at index 2 in list: {list_example[2]}")
print(f"Element at index 0 in array: {array_example[0]}")
print(f"Element at index 2 in array: {array_example[2]}")

# Modify an element of the list and array
list_example[3] = 100
array_example[3] = 100
print("List after modification:", end=" ")
for i in range(size_list):
    print(list_example[i], end=" ")
print()

print("Array after modification:", end=" ")
for i in range(size_array):
    print(array_example[i], end=" ")
print()
