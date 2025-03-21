import java.util.ArrayDeque;
import java.util.Deque;

/*
    Demonstrates the usage of `ArrayDeque` as a queue in Java.

    - While `ArrayDeque` supports strict FIFO (First In, First Out) behavior, it also allows for flexible double-ended operations.
    - `ArrayDeque` supports both FIFO and reverse (LIFO: Last In, First Out) operations efficiently.
    - Unlike `Queue` (which only allows adding at the back and removing from the front), `ArrayDeque` provides additional flexibility.

    Basic Operations:
    - addLast(item): Adds an element to the rear of the queue (FIFO).
    - removeFirst(): Removes and returns the front element (FIFO).
    - addFirst(item): Adds an element to the front of the queue (used for reverse or LIFO operations).
    - removeLast(): Removes and returns the last element (LIFO).
    - peekFirst(): Retrieves the front element without removing it (FIFO peek).
    - peekLast(): Retrieves the last element without removing it (LIFO peek).
    - size(): Returns the number of elements in the deque.
*/

public class DequeQueue {
    // Utility method to print deque elements
    public static void printDeque(Deque<String> deque) {
        if (deque.isEmpty()) {
            System.out.println("Deque is empty!");
        } else {
            System.out.println(deque);
        }
    }

    public static void main(String[] args) {
        Deque<String> deque = new ArrayDeque<>();

        // ----- Strict FIFO Queue Operations -----
        deque.addLast("a");  // Enqueue (add to rear)
        deque.addLast("b");
        deque.addLast("42");

        System.out.print("Queue after enqueues: ");
        printDeque(deque);  // Output: [a, b, 42]

        System.out.println("Front Peek: " + deque.peekFirst());  // Peek front (equivalent to front())

        deque.removeFirst();  // Dequeue (remove from front)
        System.out.print("Queue after dequeue: ");
        printDeque(deque);  // Output: [b, 42]

        // ----- Reverse Operations -----
        deque.addFirst("X");  // Enqueue at front
        System.out.print("Queue after enqueue_front: ");
        printDeque(deque);  // Output: [X, b, 42]

        System.out.println("Back Peek: " + deque.peekLast());  // Peek back (equivalent to back())

        deque.removeLast();  // Dequeue from back
        System.out.print("Queue after dequeue_back: ");
        printDeque(deque);  // Output: [X, b]
    }
}
