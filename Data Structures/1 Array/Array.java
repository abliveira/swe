public class Array {

    /* 
        An array is a collection of elements, all of the same type, stored in contiguous memory locations. 
        The elements can be accessed using an index, with the first element typically at index 0.

        Use case:
            - Arrays are useful for storing a fixed-size sequence of elements and are especially efficient for accessing elements via indices.

        Time Complexity:
            - Access: O(1), as elements can be accessed directly via indices.
            - Search: O(n), as the entire array may need to be searched for an element.
            - Insert/Remove: O(n), since elements may need to be shifted when inserting or removing elements.

        Space Complexity:
            - O(n), as the size of the array is fixed at the time of allocation and it stores n elements.

        Pros:
            - Efficient for accessing elements via indices.
            - Simple to use and implement.
            - Fixed-size storage is ideal for certain applications.

        Cons:
            - Size is fixed, and cannot be changed dynamically (unless using dynamic arrays like `ArrayList`).
            - Insertion and deletion are costly when elements need to be shifted.
    */

    public static void main(String[] args) {

        // Create an array of integers
        int[] arr = {10, 20, 30, 40, 50};

        // Calculate the size of the array
        int size = arr.length;

        // Print all elements of the array
        System.out.print("Array elements: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        // Access individual elements using indices
        System.out.println("Element at index 0: " + arr[0]);
        System.out.println("Element at index 2: " + arr[2]);

        // Modify an element of the array
        arr[3] = 100;
        System.out.print("Array after modification: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
