class LinearSearch
{
    static int search(int[] arr, int x) {
        for (int k = 0; k < arr.length; k++) {
            if (arr[k] == x)
                return k;
        }
        return -1;
    }
  
    public static void main(String[] args) {
        int[] arr = {5, 2, 42, 6, 1, 3, 2};
        System.out.print(search(arr, 42));
    }
}