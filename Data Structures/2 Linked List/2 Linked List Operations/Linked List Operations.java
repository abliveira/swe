/*
    This program demonstrates the implementation and operations of a singly linked list in Java. 
    The linked list supports the following operations:
    - Add a node at the front of the list.
    - Add a node at the end of the list.
    - Check if the list is empty.
    - Search for a node by its value.
    - Delete a specific node by its value.
    - Delete the last node in the list.
    - Count the total number of nodes in the list.
    - Print all nodes in the list.

    Each function showcases a different aspect of linked list manipulation, highlighting its 
    dynamic nature and advantages over arrays for certain operations, such as insertion and deletion.

    The main function demonstrates the usage of these operations, including:
    - Initial checks for an empty list.
    - Adding nodes at both the front and end.
    - Searching for and deleting nodes by value.
    - Deleting the last node in the list.
    - Counting and printing nodes before and after operations.
*/

class Node {
    int data;   // Data stored in the node
    Node next;  // Pointer to the next node

    // Constructor to initialize a node
    Node(int x) {
        data = x;
        next = null; // Default next pointer is null
    }
}

class LinkedList {
    Node head; // Head of the linked list

    // Constructor to initialize the list as empty
    LinkedList() {
        head = null;
    }

    // Function to check whether the list is empty
    boolean isEmpty() {
        return head == null;
    }

    // Function to add a node at the front of the list
    void addAtFront(Node n) {
        n.next = head;
        head = n;
    }

    // Function to add a node at the end of the list
    void addAtEnd(Node n) {
        if (isEmpty()) { // If the list is empty, set the node as head
            head = n;
            return;
        }
        Node last = getLastNode();
        last.next = n; // Append the node at the end
    }

    // Function to get the last node in the list
    Node getLastNode() {
        Node ptr = head;
        while (ptr != null && ptr.next != null) {
            ptr = ptr.next; // Traverse to the last node
        }
        return ptr;
    }

    // Function to search for a node by its value
    Node search(int value) {
        Node ptr = head;
        while (ptr != null) {
            if (ptr.data == value) return ptr; // Return node if found
            ptr = ptr.next;
        }
        return null; // Return null if not found
    }

    // Function to delete a node by its value
    Node deleteNode(int value) {
        if (isEmpty()) return null; // Handle empty list

        Node ptr = head;
        Node prev = null;

        // If the node to delete is the head
        if (ptr.data == value) {
            head = ptr.next;
            return ptr;
        }

        // Traverse to find the node to delete
        while (ptr != null && ptr.data != value) {
            prev = ptr;
            ptr = ptr.next;
        }

        // If the node is found, bypass it in the list
        if (ptr != null) {
            prev.next = ptr.next;
        }
        return ptr; // Return the deleted node (null if not found)
    }

    // Function to delete the last node
    Node deleteFromEnd() {
        if (isEmpty()) return null; // Handle empty list

        Node ptr = head;
        Node prev = null;

        // If the list has only one node
        if (ptr.next == null) {
            head = null;
            return ptr;
        }

        // Traverse to the second last node
        while (ptr.next != null) {
            prev = ptr;
            ptr = ptr.next;
        }

        // Remove the last node
        prev.next = null;
        return ptr;
    }

    // Function to count the total number of nodes
    int countNodes() {
        int count = 0;
        Node ptr = head;
        while (ptr != null) {
            count++;
            ptr = ptr.next;
        }
        return count; // Return the count
    }

    // Function to print the list nodes
    void printList() {
        if (isEmpty()) {
            System.out.println("List is empty!");
            return;
        }
        Node ptr = head;
        while (ptr != null) {
            System.out.print(ptr.data + " -> ");
            ptr = ptr.next;
        }
        System.out.println("NULL"); // Indicate the end of the list
    }
}

class LinkedListDemo {

    public static void main(String[] args) {

        LinkedList L = new LinkedList();

        // Check if the list is initially empty
        if (L.isEmpty()) {
            System.out.println("The list is empty.");
        }

        // Create some nodes
        Node n1 = new Node(5);
        Node n2 = new Node(8);
        Node n3 = new Node(12);

        // Add nodes to the list
        L.addAtFront(n1); // Add 5 at the front
        L.addAtFront(n2); // Add 8 at the front
        L.addAtEnd(n3);   // Add 12 at the end

        // Check again if the list is empty
        if (!L.isEmpty()) {
            System.out.println("The list is not empty.");
        }

        // Print the list
        System.out.print("Current List: ");
        L.printList();

        // Count the nodes in the list
        System.out.println("Total nodes: " + L.countNodes());

        // Delete a node by value
        Node deleted = L.deleteNode(8);
        if (deleted != null) {
            System.out.println("Deleted node with value: " + deleted.data);
        }

        // Print the list after deletion
        System.out.print("List after deleting 8: ");
        L.printList();

        // Delete the last node
        deleted = L.deleteFromEnd();
        if (deleted != null) {
            System.out.println("Deleted last node with value: " + deleted.data);
        }

        // Print the list after deleting the last node
        System.out.print("List after deleting the last node: ");
        L.printList();
    }
}
