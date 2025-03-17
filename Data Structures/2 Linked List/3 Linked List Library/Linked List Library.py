from collections import deque

'''
    Introduction:
    This example demonstrates how to use Python's deque from the collections module
    to simulate operations on a linked list. It covers insertion at both ends,
    iteration, reversing, and removing elements.
'''

# Create a deque to act as a linked list
linked_list = deque()

# Insert elements at the front
linked_list.appendleft(10)
linked_list.appendleft(20)

# Insert elements at the back
linked_list.append(30)
linked_list.append(40)

# Iterate through the list
print("Iterating through the list:", end=" ")
for i, value in enumerate(linked_list):
    print(value, end=" -> " if i < len(linked_list) - 1 else " -> null\n")

# Reverse the list
linked_list.reverse()
print("Reversed list:", end=" ")
for i, value in enumerate(linked_list):
    print(value, end=" -> " if i < len(linked_list) - 1 else " -> null\n")

# Remove elements from the front and back
linked_list.popleft()  # Removes 40 (after reverse)
linked_list.pop()      # Removes 20 (after reverse)

# Print the list after modifications
print("List after modifications:", end=" ")
for i, value in enumerate(linked_list):
    print(value, end=" -> " if i < len(linked_list) - 1 else " -> null\n")
