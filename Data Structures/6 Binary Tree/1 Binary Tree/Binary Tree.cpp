#include <iostream>
using namespace std;

/*
    A binary tree is a hierarchical data structure where each node has up to two children:
    a left child and a right child. It is a special type of graph with additional constraints.

    A key characteristic of binary trees is that they are naturally recursive. Each child node is itself the root of a smaller binary tree (called a subtree).

    Terminology:
    - Root: Topmost node.
    - Children: Nodes directly under a parent node.
    - Parent: Node directly above another node.
    - Subtree: A tree formed by a node and its descendants.
    - Internal nodes: Nodes with children.
    - Leaf: A node with no children.
    - Height: The number of nodes on the longest path from root to a leaf.

    Types of Binary Trees:
    - Full Binary Tree: Every node has either 0 or 2 children.
                       - Internal nodes (with children) must have exactly two children.
                       - Leaf nodes (without children) must have exactly zero children.

           A        		 A
          / \        		  \
         B   C       		   B
        / \          			\
       D   E          			 C   NOT Full: Nodes A and B have only one child.


    - Complete Binary Tree: All levels are fully filled except possibly the last level,
                              which is filled from left to right without any gaps.
                       - All levels up to the second-to-last level are completely full.
                       - The last level may be partially filled, but any nodes on this level
                         must be as far left as possible.

           A         A         A      	 	 	 A
          / \       / \       / \      	 		/
         B   C     B   C     B   C    	 	   B    NOT Complete: level 1 not full
        /         / \ /     /     \
       D         D   E F   D       E

    - Perfect Binary Tree: All internal nodes have two children, and all leaf nodes
                             are at the same depth (same level).
                       - A perfect binary tree is also a full and complete binary tree.
                       - All levels are completely filled.

           A           A
          / \         / \
         B   C       B   C
                    / \ / \
                   D   E F G

    Use Cases:
    - Binary Search Trees (BST): Efficient search, insertion, and deletion (O(log n) average time).
    - Heaps: Priority queues used in scheduling, graph algorithms.
    - Syntax Trees: Used in compilers and interpreters for parsing expressions.
    - Decision Trees: Used in machine learning and rule-based systems.
    - Network Routing & Hierarchical Storage: Used where structure or prioritization is required.

    Time and Space Complexity:
    - Search, Insertion, Deletion:
        - Best/Average: O(log n) in balanced trees.
        - Worst: O(n) in unbalanced trees (degenerates into a list).
    - Space: O(n) to store n nodes.

    Advantages:
    - Hierarchical structure is ideal for modeling real-world relationships.
    - Supports fast lookups and ordered data retrieval (especially in BSTs).
    - Efficient insertion/deletion in balanced trees.

    Disadvantages:
    - Performance can degrade to linear (O(n)) if the tree becomes unbalanced.
    - Requires additional logic or data structures (like AVL, Red-Black Tree) to maintain balance.
    - More complex to implement and maintain compared to arrays or linked lists.

    Program Overview:
    This program illustrates the structure of a basic binary tree by manually creating a tree with 7 nodes. Unlike a Binary Search Tree, it does not apply any rules to organize or sort the data—nodes are simply placed to demonstrate the concept. 
    The tree is displayed using a rotated 2D format to clearly show parent-child relationships. 
    Additionally, the program includes a simple example of safely deleting a portion of the tree to demonstrate memory cleanup without altering the tree’s structure.

*/


// Class to represent a single node in the binary tree
class Node {

    public:

        // The recursive nature lies in the fact that each Node contains pointers to other Nodes, forming a self-referential structure.
        int data;
        Node* left;
        Node* right;

        // Constructor initializes node with data and null children
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

// Recursive function to print the binary tree in a 2D rotated layout
void print(Node* root, int space = 0, int type = 0) {

    if (root == nullptr)
        return;

    const int INDENT = 3;  // Horizontal space between levels
    space += INDENT;

    // Print right subtree
    print(root->right, space, 1);

    // Print current node with spacing
    for (int i = INDENT; i < space; i++) {
        cout << " ";
    }

    if (type == 1) {
        cout << "/ " << root->data << endl;  // Right child
    } else if (type == 2) {
        cout << "\\ " << root->data << endl; // Left child
    } else {
        cout << root->data << endl;          // Root
    }

    // Print left subtree
    print(root->left, space, 2);
}

// Recursively delete a subtree to free memory
void deleteSubtree(Node* node) {
    if (node == nullptr)
        return;

    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

int main() {

    // Create binary tree
    Node* root = new Node(4);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(9);
    root->right->right = new Node(5);

    // Display original tree
    cout << "Original Tree:\n";
    print(root);

    // Delete the left subtree of the root node (i.e., nodes 2, 4, and 5) to demonstrate partial tree deletion (a branch), without involving any reordering or restructuring of the tree.
    deleteSubtree(root->left);
    root->left = nullptr;

    // Display updated tree after deletion
    cout << "\nTree After Deleting Left Subtree:\n";
    print(root);

    // Clean up remaining tree to avoid memory leaks
    deleteSubtree(root);
    root = nullptr;

    return 0;
}
