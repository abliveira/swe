import java.util.Random;

class Quick_Sort {

    // The QuickSort function takes an array, chooses a random pivot, 
    // partitions the array around the pivot, and recursively sorts the subarrays
    static void QuickSort(int[] arr, int left, int right) {
        int leftIndex = left;
        int rightIndex = right - 1;
        int size = right - left;

        if (size > 1) {
            Random rn = new Random();
            int pivot = arr[rn.nextInt(size) + leftIndex];

            // Partitioning the array into two subarrays based on the pivot
            while (leftIndex < rightIndex) {
                // Find elements greater than the pivot from the right side
                while (arr[rightIndex] > pivot && rightIndex > leftIndex) {
                    rightIndex--;
                }
                // Find elements smaller than the pivot from the left side
                while (arr[leftIndex] < pivot && leftIndex <= rightIndex) {
                    leftIndex++;
                }

                // If leftIndex is still less than rightIndex, swap the elements
                if (leftIndex < rightIndex) {
                    int temp = arr[leftIndex];
                    arr[leftIndex] = arr[rightIndex];
                    arr[rightIndex] = temp;
                    leftIndex++; // Move leftIndex forward
                }
            }

            // Recursively sort the two partitions
            QuickSort(arr, left, leftIndex); // Left partition
            QuickSort(arr, rightIndex, right); // Right partition
        }
    }

    static void printArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        int[] arr = {31, 4, 88, 1, 4, 2, 42};

        QuickSort(arr, 0, arr.length);

        System.out.print("Sorted array: ");
        printArray(arr);
    }
}
