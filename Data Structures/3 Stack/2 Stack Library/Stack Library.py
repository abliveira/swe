'''
    This program demonstrates the usage of Python's built-in list as a stack.

    Features:
    - Uses the LIFO (Last In, First Out) principle.
    - Provides fundamental operations: append (push), pop, top (peek), and size.
    - Uses the built-in list directly without a custom class.

    Time Complexity:
    - Append: O(1)
    - Pop: O(1)
    - Peek: O(1)
    - IsEmpty: O(1)
    - Print: O(n) (requires copying and iterating)

    Space Complexity:
    - O(n) — Directly proportional to the number of elements in the stack.
'''

# Function to print stack contents and empty it
def print_and_empty_stack(s):
    print("Printing and emptying stack (LIFO order):", end=" ")
    while s:
        print(s[-1], end=" ")
        s.pop()
    print()

def main():
    # Using a list as a stack
    stack = []  # Creating an empty stack (list)

    # append() - Adding elements to the stack
    print("Pushing elements onto the stack...")
    stack.append(67)
    stack.append(42)
    stack.append(3)
    print("3 elements pushed.\n")

    # len() - Getting the number of elements
    print(f"Stack size: {len(stack)} elements")

    # Peek - Accessing the top element
    print(f"Top element: {stack[-1]}")

    # pop() - Removing the top element
    print(f"Popping top element: {stack[-1]}")
    stack.pop()

    # Showing updated stack details after pop
    print(f"New top element after pop: {stack[-1]}")
    print(f"Stack size after pop: {len(stack)} elements\n")

    # Print and empty the stack
    print_and_empty_stack(stack)

    # Check if stack is empty
    print(f"\nIs stack empty? {'Yes' if not stack else 'No'}")

if __name__ == "__main__":
    main()
