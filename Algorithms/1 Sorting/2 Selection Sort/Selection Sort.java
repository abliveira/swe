import java.util.Arrays;

class SelectionSort {

    /*
     * Selection sort is an in-place comparison sorting algorithm.
     * It divides the input array into a sorted and unsorted part, and repeatedly selects
     * the minimum element from the unsorted part and swaps it with the first unsorted element.
     *
     * - Time Complexity: O(n^2) in all cases
     * - Space Complexity: O(1) (In-place)
     *
     * Example:
     * Given array: [3, 1, 5, 2]
     * Step 1: Find the minimum in the array [3, 1, 5, 2], which is 1.
     *         Swap it with the first element.
     *         New array: [1, 3, 5, 2]
     * Step 2: Find the minimum in the remaining array [3, 5, 2], which is 2.
     *         Swap it with the second element.
     *         New array: [1, 2, 5, 3]
     * Step 3: Find the minimum in the remaining array [5, 3], which is 3.
     *         Swap it with the third element.
     *         New array: [1, 2, 3, 5]
     */
    
    public static void selectionSort(int[] arr) {
        int size = arr.length; // Get number of elements in the array

        System.out.println("Before Sorting: " + Arrays.toString(arr)); // Print the original array

        // Outer loop to go through the array
        for (int passIdx = 0; passIdx < size; passIdx++) {
            int minIdx = passIdx; // Assume the first unsorted element is the minimum

            // Inner loop to find the minimum element in the unsorted part
            for (int currentIdx = passIdx + 1; currentIdx < size; currentIdx++) {
                if (arr[currentIdx] < arr[minIdx]) {
                    minIdx = currentIdx; // Update the index of the minimum element
                }
            }

            // Swap the found minimum element with the first unsorted element
            int temp = arr[passIdx];
            arr[passIdx] = arr[minIdx];
            arr[minIdx] = temp;
        }

        System.out.println("After Sorting: " + Arrays.toString(arr)); // Print the sorted array
    }

    public static void main(String[] args) {
        int[] array = {3, 1, 5, 2}; // Initialize the array
        selectionSort(array); // Call the selection sort method
    }
}
