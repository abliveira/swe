#include <iostream>
using namespace std;

/*
    This program demonstrates the implementation and operations of a singly linked list in C++. 
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

    The implementation also includes a destructor to ensure proper memory management, 
    cleaning up all dynamically allocated nodes when the linked list is destroyed.
*/


// Node structure
class node {
public:
    int data;    // Data stored in the node
    node* next;  // Pointer to the next node

    // Constructor to initialize a node
    node(int x) {
        data = x;
        next = nullptr; // Default next pointer is null
    }
};

// Linked List class
class LinkedList {
public:
    node* head;

    // Constructor to initialize the list as empty
    LinkedList() {
        head = nullptr;
    }

    // Function to check whether the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to add a node at the front of the list
    void addAtFront(node* n) {
        n->next = head;
        head = n;
    }

    // Function to add a node at the end of the list
    void addAtEnd(node* n) {
        if (isEmpty()) { // If the list is empty, set the node as head
            head = n;
            return;
        }
        node* last = getLastNode();
        last->next = n; // Append the node at the end
    }

    // Function to get the last node in the list
    node* getLastNode() {
        node* ptr = head;
        while (ptr && ptr->next) {
            ptr = ptr->next; // Traverse to the last node
        }
        return ptr;
    }

    // Function to search for a node by its value
    node* search(int value) {
        node* ptr = head;
        while (ptr) {
            if (ptr->data == value) return ptr; // Return node if found
            ptr = ptr->next;
        }
        return nullptr; // Return nullptr if not found
    }

    // Function to delete a node by its value
    node* deleteNode(int value) {
        if (isEmpty()) return nullptr; // Handle empty list

        node* ptr = head;
        node* prev = nullptr;

        // If the node to delete is the head
        if (ptr->data == value) {
            head = ptr->next;
            return ptr;
        }

        // Traverse to find the node to delete
        while (ptr && ptr->data != value) {
            prev = ptr;
            ptr = ptr->next;
        }

        // If the node is found, bypass it in the list
        if (ptr) {
            prev->next = ptr->next;
        }
        return ptr; // Return the deleted node (nullptr if not found)
    }

    // Function to delete the last node
    node* deleteFromEnd() {
        if (isEmpty()) return nullptr; // Handle empty list

        node* ptr = head;
        node* prev = nullptr;

        // If the list has only one node
        if (!ptr->next) {
            head = nullptr;
            return ptr;
        }

        // Traverse to the second last node
        while (ptr->next) {
            prev = ptr;
            ptr = ptr->next;
        }

        // Remove the last node
        prev->next = nullptr;
        return ptr;
    }

    // Function to count the total number of nodes
    int countNodes() {
        int count = 0;
        node* ptr = head;
        while (ptr) {
            count++;
            ptr = ptr->next;
        }
        return count; // Return the count
    }

    // Function to print the list nodes
    void printList() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        node* ptr = head;
        while (ptr) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl; // Indicate the end of the list
    }

    // Destructor to clean up memory
    ~LinkedList() {
        node* ptr = head;
        while (ptr) {
            node* temp = ptr;
            ptr = ptr->next;
            delete temp; // Free each node
        }
        head = nullptr;
    }
};

int main() {
    LinkedList L;

    // Check if the list is initially empty
    if (L.isEmpty()) {
        cout << "The list is empty." << endl;
    }

    // Create some nodes
    node* n1 = new node(5);
    node* n2 = new node(8);
    node* n3 = new node(12);

    // Add nodes to the list
    L.addAtFront(n1); // Add 5 at the front
    L.addAtFront(n2); // Add 8 at the front
    L.addAtEnd(n3);   // Add 12 at the end

    // Check again if the list is empty
    if (!L.isEmpty()) {
        cout << "The list is not empty." << endl;
    }

    // Print the list
    cout << "Current List: ";
    L.printList();

    // Count the nodes in the list
    cout << "Total nodes: " << L.countNodes() << endl;

    // Delete a node by value
    node* deleted = L.deleteNode(8);
    if (deleted) {
        cout << "Deleted node with value: " << deleted->data << endl;
        delete deleted;
    }

    // Print the list after deletion
    cout << "List after deleting 8: ";
    L.printList();

    // Delete the last node
    deleted = L.deleteFromEnd();
    if (deleted) {
        cout << "Deleted last node with value: " << deleted->data << endl;
        delete deleted;
    }

    // Print the list after deleting the last node
    cout << "List after deleting the last node: ";
    L.printList();

    // Cleanup (handled automatically by the destructor)
    return 0;
}
