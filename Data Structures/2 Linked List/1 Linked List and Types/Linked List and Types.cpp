#include <iostream>
using namespace std;

/*
    A linked list is a linear data structure (elements are accessed sequentially through pointers) consisting of nodes, where each node stores its own data and a pointer (address) to the location of the next node. One node links to another, forming what can be thought of as a linked chain. The last item in the list typically has a link to NULL, indicating the end of the chain.

    Linked lists are commonly used as the fundamental building block for implementing data structures such as stacks, queues, trees, and graphs.

    Unlike arrays, linked lists are not restricted to a fixed size. They allow dynamic memory allocation and support efficient insertion or removal of elements without reallocation or reorganization of the entire structure.

    Use Case:
        - Useful for scenarios with frequent insertions and deletions.
        - Widely applied in implementing stacks, queues, dynamic memory allocation, and adjacency lists for graphs.

    Navigation:
        - Traversal: Singly linked lists can only move forward, while doubly linked lists support bidirectional traversal.
        - Circular Links: Circular variants connect the last node back to the first, enabling cyclic navigation.
    
    Types of Linked Lists:
        1. Singly Linked List: Each node points to the next node; traversal is unidirectional.
        2. Circular Linked List: Similar to a singly linked list, but the last node points back to the head. Can also exist in doubly linked form.
        3. Doubly Linked List: Each node has pointers to both the next and previous nodes, allowing bidirectional traversal.
        4. Doubly Circular Linked List: Combines circular and doubly linked list properties for fully circular bidirectional traversal.

    Time Complexity:
        - Access/Search: O(n), as elements must be accessed sequentially.
        - Insert/Remove: O(1) for operations at the beginning, O(n) elsewhere due to traversal.

    Pros:
        - Supports dynamic size adjustment, avoiding the need for a predefined size.
        - Efficient insertion and deletion at the beginning or middle, as no element shifting is required.
        - Easily divided or merged, making it suitable for algorithms like merge sort.
        - Allocates memory as needed, avoiding memory waste and allowing usage in fragmented memory scenarios.
        - Does not require contiguous memory allocation, unlike arrays.

    Cons:
        - Does not support random access; nodes must be traversed sequentially, making searching slower than arrays.
        - Requires extra memory for pointer/reference fields, adding overhead.
        - Indirection through pointers leads to slower access times compared to arrays.
        - More complex to implement and debug compared to arrays.
        - Inefficient for small data elements where pointer memory may outweigh the actual data size.
*/


// Singly Linked List

struct SinglyNode {
    int data;
    SinglyNode* next;
};

void singlyLinkedListDemo() {
    // Create three nodes with data values
    SinglyNode* head = new SinglyNode{10, nullptr};
    SinglyNode* second = new SinglyNode{20, nullptr};
    SinglyNode* third = new SinglyNode{30, nullptr};

    // Link the nodes together to form a singly linked list
    head->next = second;
    second->next = third;

    // Start traversing the list from the head node
    cout << "Singly Linked List: ";
    SinglyNode* temp = head;
    while (temp) {  // Traverse the list until the last node (NULL)
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    }
    cout << endl;

    // Clean up memory to avoid memory leaks
    delete head;
    delete second;
    delete third;

    /*
        Explanation of Function:
        singlyLinkedListDemo()
        - Demonstrates a singly linked list with three nodes.
        - Traverses and prints the list in a single direction.
        - The list is unidirectional, meaning we can only traverse from head to tail.
    */
}


// Circular Linked List

struct CircularNode {
    int data;
    CircularNode* next;
};

void circularLinkedListDemo() {
    // Create three nodes for the circular linked list
    CircularNode* head = new CircularNode{10, nullptr};
    CircularNode* second = new CircularNode{20, nullptr};
    CircularNode* third = new CircularNode{30, nullptr};

    // Link the nodes together to form the circular linked list
    head->next = second;
    second->next = third;
    third->next = head;  // Points back to the head, making it circular

    // Start traversing the circular list, which requires stopping condition
    cout << "Circular Linked List: ";
    CircularNode* temp = head;
    do {  // Do-while loop ensures we traverse at least once
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    } while (temp != head);  // Stop when we reach the head again
    cout << endl;

    // Clean up memory (note: actual deletion is a bit trickier for circular lists)
    delete head;
    delete second;
    delete third;
}


// Doubly Linked List

struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
};

void doublyLinkedListDemo() {
    // Create three nodes with data values
    DoublyNode* head = new DoublyNode{10, nullptr, nullptr};
    DoublyNode* second = new DoublyNode{20, nullptr, nullptr};
    DoublyNode* third = new DoublyNode{30, nullptr, nullptr};

    // Link the nodes together to form the doubly linked list
    head->next = second;
    second->prev = head;  // Linking the previous pointer of second node
    second->next = third;
    third->prev = second;  // Linking the previous pointer of third node

    // Traverse the doubly linked list forward
    cout << "Doubly Linked List (Forward): ";
    DoublyNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    }
    cout << endl;

    // Traverse the doubly linked list backward from the last node
    cout << "Doubly Linked List (Backward): ";
    temp = third;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;  // Move to the previous node
    }
    cout << endl;

    // Clean up memory
    delete head;
    delete second;
    delete third;
}


// Doubly Circular Linked List

struct DoublyCircularNode {
    int data;
    DoublyCircularNode* prev;
    DoublyCircularNode* next;
};

void doublyCircularLinkedListDemo() {
    // Create three nodes for the doubly circular linked list
    DoublyCircularNode* head = new DoublyCircularNode{10, nullptr, nullptr};
    DoublyCircularNode* second = new DoublyCircularNode{20, nullptr, nullptr};
    DoublyCircularNode* third = new DoublyCircularNode{30, nullptr, nullptr};

    // Link the nodes together to form the doubly circular linked list
    head->next = second;
    second->prev = head;  // Link the previous pointer of second node
    second->next = third;
    third->prev = second;  // Link the previous pointer of third node

    third->next = head;  // Circular: last node points to the head
    head->prev = third;  // Circular: head's previous points to the last node

    // Traverse the doubly circular list forward
    cout << "Doubly Circular Linked List (Forward): ";
    DoublyCircularNode* temp = head;
    do {  // Do-while ensures traversal happens at least once
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    } while (temp != head);  // Stop when we reach the head again
    cout << endl;

    // Traverse the doubly circular list backward from the last node
    cout << "Doubly Circular Linked List (Backward): ";
    temp = head->prev;  // Start from the last node
    do {
        cout << temp->data << " ";
        temp = temp->prev;  // Move to the previous node
    } while (temp != head->prev);  // Stop when we reach the last node again
    cout << endl;

    // Clean up memory (note: actual deletion is tricky in circular lists)
    delete head;
    delete second;
    delete third;
}

int main() {

    singlyLinkedListDemo();
    circularLinkedListDemo();
    doublyLinkedListDemo();
    doublyCircularLinkedListDemo();

    return 0;
}
