/* 
    This program demonstrates the implementation of a stack using a singly linked list.

    In this implementation, the stack follows the LIFO (Last In, First Out) principle, 
    where the last element added is the first to be removed. A `Node` class is used to 
    represent each element, and each node points to the next one in the stack. The `Stack` class 
    manages the stack operations, allowing elements to be added (push), removed (pop), and printed.

    The stack supports the following primary operations:
    - Push: Add an element to the top of the stack.
    - Pop: Remove the top element from the stack.
    - Print: Display the contents of the stack.
    
    Note:
        - This version uses a linked list to implement the stack, as opposed to an array-based 
          implementation or a built-in library version.
        - It's worth noting that Java provides a built-in `Stack` class in the `java.util` package, 
          which can be used for stack operations without the need to implement from scratch.
*/

public class Stack {
    
    static class Node {
        int value;
        Node next;
    
        public Node(int value) {
            this.value = value;
        }
    }

    private Node first = null;  // Pointer to the top of the stack

    // Push a new node onto the stack
    public void push(Node node) {
        node.next = first;  // Link the new node to the current top
        first = node;  // Update the top pointer to the new node
    }

    // Pop the top node from the stack
    public void pop() {
        if (first != null) {
            first = first.next;  // Move the top pointer to the next node
        }
    }

    // Print all elements of the stack
    public void print() {
        Node node = first;  // Start from the top of the stack
        while (node != null) {
            System.out.println("|" + node.value + "|");
            node = node.next;  // Move to the next node
        }
    }

    public static void main(String[] args) {
        Stack s = new Stack();
        
        // Push elements onto the stack
        s.push(new Node(1));
        s.push(new Node(2));
        s.push(new Node(4));
        s.push(new Node(8));

        // Print the stack contents
        s.print();
    }
}
