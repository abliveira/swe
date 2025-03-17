'''
    This program demonstrates the implementation of a stack using a list in Python.

    A stack follows the LIFO (Last In, First Out) principle, where the last element added 
    is the first to be removed. In this implementation, we use a list to represent the stack, 
    and the stack operations (push, pop, is_empty, print_stack) are implemented as methods 
    of the `Stack` class.
    #
    The stack supports the following primary operations:
    - push: Add an element to the top of the stack.
    - pop: Remove the top element from the stack.
    - is_empty: Check if the stack is empty.
    - print_stack: Display the contents of the stack.

    Note:
    - While this example uses a list to implement the stack, Python also provides built-in 
        collections like `deque` from the `collections` module, which is optimized for operations 
        on both ends (push/pop). 
    - Using a list for stack operations is simple and works well for smaller datasets, but 
        for more efficient implementations, especially when frequent inserts and pops are needed, 
        `deque` might be a better choice.
'''

class Stack:
    def __init__(self):
        self.items = []  # List to hold stack items

    def is_empty(self):
        return self.items == []  # Check if stack is empty

    def push(self, item):
        self.items.insert(0, item)  # Add item to the top (beginning of the list)

    def pop(self):
        return self.items.pop(0)  # Remove and return the top item

    def print_stack(self):
        print(self.items)  # Print stack contents

# Create a stack instance
s = Stack()

# Push elements onto the stack
s.push('a')
s.push('b')
s.push('c')

# Print the stack contents
s.print_stack()

# Pop the top element and print the stack again
s.pop()
s.print_stack()
