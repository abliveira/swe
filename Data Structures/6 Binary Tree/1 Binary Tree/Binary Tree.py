"""
A binary tree is a hierarchical data structure where each node has up to two children:
a left child and a right child. It is a special type of graph with additional constraints.

Program Overview:
  This program illustrates the structure of a basic binary tree by manually creating a tree with 7 nodes. 
  Unlike a Binary Search Tree, it does not apply any rules to organize or sort the data—nodes are simply placed to demonstrate the concept.
  The tree is displayed using a rotated 2D format to clearly show parent-child relationships.
  Additionally, the program includes a simple example of safely deleting a portion of the tree to demonstrate memory cleanup without altering the tree’s structure.

Differences from the C++ version:
  - Python handles memory management automatically via garbage collection.
  - Instead of manual deletion, we remove references to help the garbage collector reclaim memory.
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Recursive function to print the binary tree in a 2D rotated layout
def print_tree(root, space=0, node_type=0):
    if root is None:
        return

    INDENT = 3
    space += INDENT

    print_tree(root.right, space, 1)

    print(" " * (space - INDENT), end="")
    if node_type == 1:
        print("/ " + str(root.data))
    elif node_type == 2:
        print("\\ " + str(root.data))
    else:
        print(root.data)

    print_tree(root.left, space, 2)

# Recursively remove references in a subtree
def delete_subtree(node):
    if node is None:
        return
    delete_subtree(node.left)
    delete_subtree(node.right)
    node.left = None
    node.right = None

def main():
    # Construct binary tree manually (no logic like BSTs)
    root = Node(4)
    root.left = Node(10)
    root.right = Node(2)
    root.left.left = Node(7)
    root.left.right = Node(1)
    root.right.left = Node(9)
    root.right.right = Node(5)

    print("Original Tree:")
    print_tree(root)

    # Delete left subtree (simulate safe memory handling)
    # No restructuring — we simply remove references
    delete_subtree(root.left)
    root.left = None

    print("\nTree After Deleting Left Subtree:")
    print_tree(root)

    # Clean up entire tree
    delete_subtree(root)
    root = None

if __name__ == "__main__":
    main()
