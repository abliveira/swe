"""
    Binary Search Tree (BST) Demo

    This version mirrors the functionality of the previous C++ BST demo.

    Differences are primarily due to Python’s dynamic typing and automatic memory management:
    - No explicit nullification is required for cleanup—Python's garbage collector handles it.

    Program Features:
    - Dynamically builds the BST using insertions
    - Displays the tree using a rotated 2D view
    - Relies on Python's garbage collection for cleanup
    - Uses value-based placement (no manual node wiring)
    - Maintains sorted structure
"""

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return Node(val)
    if val < root.data:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def print_tree(root, space=0, node_type=0):
    if root is None:
        return

    INDENT = 3
    space += INDENT

    print_tree(root.right, space, 1)

    print(" " * (space - INDENT), end="")
    if node_type == 1:
        print(f"/ {root.data}")
    elif node_type == 2:
        print(f"\\ {root.data}")
    else:
        print(root.data)

    print_tree(root.left, space, 2)

def delete_tree(node):
    # In Python, setting references to None allows garbage collection
    if node is None:
        return
    delete_tree(node.left)
    delete_tree(node.right)
    node.left = None
    node.right = None

if __name__ == "__main__":
    root = None

    # Insert values into the BST
    values = [5, 3, 8, 1, 4, 7, 9, 0, 2, 6, 10]
    for val in values:
        root = insert(root, val)

    """
             5
           /   \
         3       8
        / \     / \
       1   4   7   9
      / \       \
     0   2       6
                  \
                  10
    """

    # Print the BST
    print("Binary Search Tree:")
    print_tree(root)

    # Clean up (optional in Python)
    delete_tree(root)
    root = None
