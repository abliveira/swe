#include <iostream>
using namespace std;

/*
    Recursion is a process where a function calls itself directly or indirectly to solve a problem.
    It is particularly useful for problems that can be divided into smaller subproblems of the 
    same nature.

    How it works:
    - The recursive function repeatedly breaks down a problem into smaller subproblems until it reaches
      a base case, which stops the recursion.
    - After reaching the base case, the function resolves the subproblems step-by-step as it returns 
      back through the recursive calls.

    Pros:
        - Elegant and intuitive for problems that can be divided into smaller subproblems (e.g., trees, graphs).
        - Reduces the need for iterative loops in some cases.

    Cons:
        - May lead to high memory usage (stack overflow) for deep recursion.
        - Recursive solutions are often less efficient than iterative ones for the same problem.
*/

// Example 1: Factorial of a Number (O(n))
int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // Base case
    return n * factorial(n - 1);     // Recursive case
}

// Example 2: Sum of Elements in an Array (O(n))
int arraySum(int arr[], int size) {
    if (size == 0) return 0; // Base case
    return arr[size - 1] + arraySum(arr, size - 1); // Recursive case
}

// Example 3: Power of a Number (O(n))
int power(int base, int exponent) {
    if (exponent == 0) return 1; // Base case: Any number to the power of 0 is 1
    return base * power(base, exponent - 1); // Recursive case
}

int main() {

    // Factorial Example
    cout << "Factorial of 5: " << factorial(5) << endl;

    // Sum of Array Example
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of array elements: " << arraySum(arr, size) << endl;

    // Power of a Number Example
    cout << "3 to the power of 4: " << power(3, 4) << endl;

    return 0;
}
