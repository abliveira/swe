/*
    This program demonstrates the implementation of a queue using a singly linked list.

    The queue follows the FIFO (First In, First Out) principle, where elements are added at the rear 
    and removed from the front. A `Node` class represents each element, and the `Queue` class 
    manages enqueue, dequeue, and print operations.

    Primary operations:
    - Enqueue: Add an element to the rear.
    - Dequeue: Remove an element from the front.
    - Print: Display the contents of the queue.

    Note:
    - This version uses a linked list instead of an array-based or built-in implementation.
    - Java provides a built-in `Queue` interface in `java.util`, which can be used instead.
*/

public class Queue {
    
    // Node class representing an element in the queue
    static class Node {
        int data;  // Data stored in the node
        Node next; // Pointer to the next node

        public Node(int data) {
            this.data = data;
            this.next = null; // Initially, no next node
        }
    }
    
    private Node front; // Pointer to the front of the queue
    private Node rear;  // Pointer to the rear of the queue

    // Constructor to initialize an empty queue
    public Queue() {
        this.front = this.rear = null;
    }

    // Add a new element to the rear of the queue
    public void enqueue(int data) {
        Node newNode = new Node(data);
        if (rear == null) { // If queue is empty, front and rear are the same
            front = rear = newNode;
        } else {
            rear.next = newNode; // Link the new node at the end
            rear = newNode; // Update rear pointer
        }
    }
    
    // Remove an element from the front of the queue
    public void dequeue() {
        if (front == null) {
            System.out.println("Queue is empty, cannot dequeue!");
            return;
        }
        front = front.next; // Move front to the next element
        if (front == null) { // If queue is now empty, reset rear
            rear = null;
        }
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return front == null;
    }

    // Print all elements in the queue
    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        Node temp = front; // Start from the front
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null"); // Indicate the end of the queue
    }
        
    public static void main(String[] args) {
        Queue q = new Queue(); // Create a queue object

        // Enqueue elements
        q.enqueue(7);
        q.enqueue(78);
        q.enqueue(11);

        System.out.println("Queue contents after enqueues:");
        q.print();

        // Dequeue an element
        q.dequeue();
        System.out.println("Queue contents after dequeue:");
        q.print();
    }
}
