#include <iostream>
using namespace std;

/*
    A Binary Search Tree (BST) is a type of binary tree that maintains a specific ordering property:
    - For any given node:
        - All nodes in its left subtree contain values less than the node’s value.
        - All nodes in its right subtree contain values greater than the node’s value.

    This property allows for fast and efficient searching, insertion, and deletion operations,
    making BSTs an important foundation in many computing problems.

    Key Characteristics:
    - Each node has at most two children (like all binary trees).
    - BSTs are inherently recursive: each subtree is itself a BST.
    - The structure and balance of a BST depend on the order of insertions.

    Time and Space Complexity:
    - Search, Insertion, Deletion:
        - Best/Average Case: O(log n) in a balanced BST.
        - Worst Case: O(n) if the tree becomes skewed (e.g., sorted insertions).
    - Space Complexity: O(n) to store n nodes.

    Use Cases:
    - Lookup tables (with fast key retrieval)
    - Sets and Maps (unique, ordered data)
    - In-memory databases
    - Auto-completion systems (when combined with other data structures)
    - Range queries and order statistics (via augmented BSTs)

    Advantages:
    - Enables efficient binary search operations.
    - Simplifies implementation of ordered traversal (e.g., in-order yields sorted data).

    Cons:
    - BSTs can become unbalanced depending on insertion order.
    - Maintaining balance requires additional structures like AVL trees or Red-Black Trees.

    Program Overview:
    This program illustrates the structure and behavior of a basic Binary Search Tree (BST),
    where nodes are inserted according to their values to maintain the BST property:
    left child < parent < right child.

    Features:
    - Dynamically builds the tree via value-based insertions
    - Maintains BST ordering automatically during insertion
    - Visualizes the tree in a rotated 2D format to show parent-child relationships
    - Recursively deletes all nodes for proper memory cleanup

    Note: The tree may appear balanced depending on insertion order, but no self-balancing
    logic is implemented (e.g., AVL or Red-Black Tree).

*/

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a new value into the BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Print the tree in rotated 2D view
void print(Node* root, int space = 0, int type = 0) {
    if (!root) return;

    const int INDENT = 3;
    space += INDENT;

    print(root->right, space, 1);

    for (int i = INDENT; i < space; ++i) cout << " ";

    if (type == 1) cout << "/ " << root->data << endl;
    else if (type == 2) cout << "\\ " << root->data << endl;
    else cout << root->data << endl;

    print(root->left, space, 2);
}

// Recursively delete all nodes in the tree
void deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Node* root = nullptr;

    // Insert values into the BST
    int values[] = {5, 3, 8, 1, 4, 7, 9, 0, 2, 6, 10};
    for (int val : values) {
        root = insert(root, val);
    }

    /*
             5
           /   \
         3       8
        / \     / \
       1   4   7   9
      / \       \
     0   2       6
                  \
                  10
    */

    // Print the BST
    cout << "Binary Search Tree:\n";
    print(root);

    // Clean up
    deleteTree(root);
    root = nullptr;

    return 0;
}
