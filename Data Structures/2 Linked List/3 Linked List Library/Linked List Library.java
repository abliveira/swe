import java.util.LinkedList; // Linked list library
import java.util.Collections; // Auxiliar library
import java.util.Iterator; // Auxiliar library

/*
    This program demonstrates the use of the Java Collections Framework `LinkedList` class, 
    which implements a doubly linked list. The example showcases various linked list operations, including:

    - Adding elements at the front and back (`addFirst` and `addLast`)
    - Accessing the first and last elements (`getFirst` and `getLast`)
    - Removing elements from the front and back (`removeFirst` and `removeLast`)
    - Inserting elements at specific positions
    - Removing specific elements by value
    - Reversing the list (using a helper method)
    - Sorting the list (using `Collections.sort`)

    This program highlights how `LinkedList` abstracts the complexity of linked list management 
    and provides utility functions for efficient and flexible operations.
*/

/*
    This program demonstrates the use of Java's `LinkedList` class, showcasing operations
    such as adding, removing, and accessing elements. Additionally, it demonstrates the use 
    of iterators for traversal and the `Collections` utility class for reversing the list.

    Operations included:
    - Adding elements at the front and back.
    - Removing elements by position and value.
    - Iterating over the list using an iterator.
    - Reversing the list using the Collections utility class.
*/

class LinkedListLib {
    public static void main(String[] args) {
        // Create a LinkedList of integers
        LinkedList<Integer> linkedList = new LinkedList<>();

        // Insert elements at the front
        linkedList.addFirst(10);
        linkedList.addFirst(20);

        // Insert elements at the back
        linkedList.addLast(30);
        linkedList.addLast(40);

        // Print the current list
        System.out.println("Initial LinkedList: " + linkedList);

        // Access and print the first and last elements
        System.out.println("First element: " + linkedList.getFirst());
        System.out.println("Last element: " + linkedList.getLast());

        // Remove elements from the front and back
        linkedList.removeFirst();
        linkedList.removeLast();
        System.out.println("After removing first and last elements: " + linkedList);

        // Insert an element at a specific position
        linkedList.add(1, 25); // Add 25 at index 1
        System.out.println("After inserting 25 at index 1: " + linkedList);

        // Remove a specific element by value (30)
        linkedList.remove(Integer.valueOf(30));
        System.out.println("After removing element 30: " + linkedList);

        // Use an iterator to traverse the list
        System.out.print("Iterating through the list: ");
        Iterator<Integer> iterator = linkedList.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " -> ");
        }
        System.out.println("null");

        // Reverse the linked list using Collections
        Collections.reverse(linkedList);
        System.out.println("After reversing the LinkedList: " + linkedList);
    }
}
