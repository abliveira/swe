import java.util.Stack;  // Importing the Java Stack library

/*
    This program demonstrates the usage of the Java Standard Library `Stack`.

    Features:
    - Uses the LIFO (Last In, First Out) principle.
    - Provides fundamental operations: push, pop, peek (top), empty, and size.
    - Uses `Stack<Integer>` directly in `main()` without a custom class.

    Time Complexity:
    - Push: O(1)
    - Pop: O(1)
    - Peek: O(1)
    - isEmpty: O(1)
    - Print: O(n) (requires copying and iterating)

    Space Complexity:
    - O(n) — Directly proportional to the number of elements in the stack.
*/

// Function to print stack contents and empty it
public static void printAndEmptyStack(Stack<Integer> s) {
    System.out.print("Printing and emptying stack (LIFO order): ");
    while (!s.isEmpty()) {
        System.out.print(s.peek() + " ");
        s.pop();
    }
    System.out.println();
}

public static void main(String[] args) {
    Stack<Integer> S = new Stack<>();  // Creating a stack using the standard library

    // push() - Adding elements to the stack
    System.out.println("Pushing elements onto the stack...");
    S.push(67);
    S.push(42);
    S.push(3);
    System.out.println("3 elements pushed.\n");

    // size() - Getting the number of elements
    System.out.println("Stack size: " + S.size() + " elements");

    // peek() - Accessing the top element
    System.out.println("Top element: " + S.peek());

    // pop() - Removing the top element
    System.out.println("Popping top element: " + S.peek());
    S.pop();

    // Showing updated stack details after pop
    System.out.println("New top element after pop: " + S.peek());
    System.out.println("Stack size after pop: " + S.size() + " elements\n");

    // print and empty operation
    printAndEmptyStack(S);

    // empty() - Checking if stack is empty
    System.out.println("\nIs stack empty? " + (S.isEmpty() ? "Yes" : "No"));
}
