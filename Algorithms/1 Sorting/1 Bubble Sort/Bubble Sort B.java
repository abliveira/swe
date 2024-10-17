class BubbleSort
{
    static void bubbleSort(int[] arr) {
        boolean swapped = true;
        for(int passIndex = 0; passIndex < arr.length - 1; passIndex++) {
            swapped = false;
            for(int currentIndex = 0; currentIndex < arr.length - passIndex - 1; currentIndex++) {
                if(arr[currentIndex] > arr[currentIndex + 1]) {
                    int temporary = arr[currentIndex];
                    arr[currentIndex] = arr[currentIndex + 1];
                    arr[currentIndex + 1] = temporary;
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }
    }

    static void printarr(int[] arr) {
        for(int index = 0; index < arr.length; index++) {
            System.out.print(arr[index] + " ");
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 3, 2, 4};
        bubbleSort(arr);
        printarr(arr);
    }
}
