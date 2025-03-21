import java.util.LinkedList;
import java.util.Queue;

/*
    Demonstrates the usage of `Queue` from the Java Collections Framework.

    - Follows the FIFO (First In, First Out) principle.
    - Provides essential operations: add, poll, peek, isEmpty, and size.
    - Uses `Queue<Integer>` directly in `main()` without a custom class.

    Complexity:
    - Enqueue (add): O(1)
    - Dequeue (poll): O(1)
    - Front access (peek): O(1)
    - isEmpty: O(1)
    - Size: O(1)
    - Print: O(n) (requires iterating through elements)

    Space Complexity:
    - O(n) — Proportional to the number of stored elements.
*/

public class QueueExample {
    
    // Utility function to print queue contents
    public static void printQueue(Queue<Integer> q) {
        if (q.isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }

        for (Integer item : q) {
            System.out.print(item + " -> ");
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();  // Create a queue of integers

        // Enqueue elements
        q.add(7);
        q.add(78);
        q.add(11);

        // Print queue contents after enqueue
        System.out.println("Queue contents after enqueues:");
        printQueue(q);

        // Peek at the front element
        System.out.println("Front element (peek): " + q.peek());

        // Check queue size
        System.out.println("Queue size: " + q.size());

        // Dequeue one element
        q.poll();

        // Print queue contents after dequeue
        System.out.println("Queue contents after dequeue:");
        printQueue(q);

        // Peek again after dequeue
        System.out.println("Front element after dequeue (peek): " + q.peek());

        // Final queue size
        System.out.println("Queue size after dequeue: " + q.size());
    }
}
