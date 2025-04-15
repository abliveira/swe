/*
    A binary tree is a hierarchical data structure where each node has up to two children:
    a left child and a right child. It is a special type of graph with additional constraints.

    Program Overview:
      This program illustrates the structure of a basic binary tree by manually creating a tree with 7 nodes. Unlike a Binary Search Tree, it does not apply any rules to organize or sort the data—nodes are simply placed to demonstrate the concept. 
      The tree is displayed using a rotated 2D format to clearly show parent-child relationships. 
      Additionally, the program includes a simple example of safely deleting a portion of the tree to demonstrate memory cleanup without altering the tree’s structure.

    Differences from the C++ version:
      - Memory management is handled by the garbage collector; however, we still nullify references to assist GC.
*/

class BinaryTreeDemo {

  // Static nested class to represent a single node
  static class Node {
      int data;
      Node left;
      Node right;

      Node(int data) {
          this.data = data;
          this.left = null;
          this.right = null;
      }
  }

  // Recursive method to print the binary tree in a 2D rotated layout
  static void printTree(Node root, int space, int type) {
      if (root == null)
          return;

      final int INDENT = 3;
      space += INDENT;

      printTree(root.right, space, 1);

      for (int i = INDENT; i < space; i++) {
          System.out.print(" ");
      }

      if (type == 1) {
          System.out.println("/ " + root.data);  // Right child
      } else if (type == 2) {
          System.out.println("\\ " + root.data); // Left child
      } else {
          System.out.println(root.data);         // Root
      }

      printTree(root.left, space, 2);
  }

  // Recursively nullify references to simulate deletion
  static void deleteSubtree(Node node) {
      if (node == null)
          return;

      deleteSubtree(node.left);
      deleteSubtree(node.right);

      // Help the garbage collector by breaking references
      node.left = null;
      node.right = null;
  }

  public static void main(String[] args) {

      // Construct binary tree manually (no sorting or ordering logic like in BSTs)
      Node root = new Node(4);
      root.left = new Node(10);
      root.right = new Node(2);
      root.left.left = new Node(7);
      root.left.right = new Node(1);
      root.right.left = new Node(9);
      root.right.right = new Node(5);
      

      // Display the original tree
      System.out.println("Original Tree:");
      printTree(root, 0, 0);

      // Delete left subtree to simulate safe memory handling
      // (no restructuring, just break references for GC to clean up)
      deleteSubtree(root.left);
      root.left = null;

      // Display the tree after deletion
      System.out.println("\nTree After Deleting Left Subtree:");
      printTree(root, 0, 0);

      // Clean up remaining nodes
      deleteSubtree(root);
      root = null;
  }
}
