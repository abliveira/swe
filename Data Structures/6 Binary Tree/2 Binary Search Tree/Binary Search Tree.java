/*
    Binary Search Tree (BST) Demo

    This version mirrors the functionality of the previous C++ BST demo.

    The key differences lie in how memory is managed and how objects are handled: Cleanup is done by nullifying references to assist Java's garbage collector.

    Program Features:
    - Dynamically builds the BST using insertions
    - Displays the tree using a rotated 2D view
    - Supports memory cleanup by nullifying all references
    - Uses value-based placement (no manual node wiring)
    - Maintains sorted structure
*/

class BSTDemo {

    // Static nested class to represent a single node
    static class Node {
        int data;
        Node left, right;

        Node(int val) {
            this.data = val;
            this.left = null;
            this.right = null;
        }
    }

    // Insert a new value into the BST
    static Node insert(Node root, int val) {
        if (root == null) return new Node(val);
        if (val < root.data)
            root.left = insert(root.left, val);
        else
            root.right = insert(root.right, val);
        return root;
    }

    // Print the tree in rotated 2D view
    static void printTree(Node root, int space, int type) {
        if (root == null) return;

        final int INDENT = 3;
        space += INDENT;

        printTree(root.right, space, 1);

        for (int i = INDENT; i < space; i++) {
            System.out.print(" ");
        }

        if (type == 1)
            System.out.println("/ " + root.data);
        else if (type == 2)
            System.out.println("\\ " + root.data);
        else
            System.out.println(root.data);

        printTree(root.left, space, 2);
    }

    // Recursively nullify references to simulate deletion
    static void deleteTree(Node node) {
        if (node == null) return;

        deleteTree(node.left);
        deleteTree(node.right);

        node.left = null;
        node.right = null;
    }

    public static void main(String[] args) {
        Node root = null;

        // Insert values into the BST
        int[] values = {5, 3, 8, 1, 4, 7, 9, 0, 2, 6, 10};
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
        System.out.println("Binary Search Tree:");
        printTree(root, 0, 0);

        // Clean up
        deleteTree(root);
        root = null;
    }
}
