class InsertionSort {
    static void InsertionSort(int arr[]) {
        int j;
        for(int i=1; i<arr.length; i++) {
            j = i;
            while(j>0 && arr[j-1] > arr[j]) {
                //swap
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                
                j = j-1;
            }
        }
    }

    public static void main(String args[]) { 
        int arr[] = {5, 2, 42, 6, 1, 3, 2};
        InsertionSort(arr);
        
        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}
