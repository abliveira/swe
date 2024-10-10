#include <iostream>
using namespace std;

/*
    Time complexity refers to the computational complexity that 
    measures or estimates the time taken for running an algorithm.

    Time complexity is commonly estimated by counting the number of elementary 
    operations performed by the algorithm, assuming that an elementary operation 
    takes a fixed amount of time to perform.

    Since an algorithm's running time may vary with different inputs of the same 
    size, the worst-case time complexity is commonly considered. This is often 
    expressed using Big-O notation, which represents the maximum amount of time 
    an algorithm takes for inputs of a given size.

    For example, an algorithm with time complexity O(n) is a linear-time algorithm, 
    meaning that the time required grows linearly with the input size.

    Excluding Lower-Order Constants:

    It is common to exclude lower-order constants and coefficients that don’t 
    have a significant impact on the overall complexity of the problem. 
    For example, O(2n) or O(n + 5) is simplified to O(n), as lower-order terms 
    become insignificant as input size grows.

    Common Time Complexities:

    O(1) - Constant Time:
    - Given an input of size `n`, it takes a single step for the algorithm to 
      accomplish the task.
    - Common examples include access to an element in an array.

    O(n) - Linear Time:
    - The running time increases at most linearly with the size of the input.
    - Examples include iterating through an array.

    O(log n) - Logarithmic Time:
    - The number of steps to accomplish the task is reduced by a constant factor 
      (such as halving) at each step.
    - A common example is binary search, where the input size is reduced by half 
      with each iteration.

    O(n log n) - Quasilinear Time:
    - In many cases, this is the result of performing an O(log n) operation `n` times.
    - Examples include efficient sorting algorithms like merge sort and heapsort.

    O(n²) - Quadratic Time:
    - The time complexity grows quadratically with the input size, often due to 
      nested loops.
    - Sorting algorithms like bubble sort and selection sort typically run in O(n²).

    O(2ⁿ) - Exponential Time:
    - The time complexity doubles with each addition to the input size.
    - A common example is computing the Fibonacci sequence using recursion.

    O(n!) - Factorial Time:
    - Commonly seen when generating all permutations of a set.
    - Factorial time complexity grows extremely fast with input size.

References:
    SoloLearn / Aaron Sarkissian

*/


// O(1) - Constant time
// Example: Accessing an element in an array.
void constantTimeExample() {
    cout << "O(1) - Constant Time Example\n";
    int arr[] = {1, 2, 3, 4};
    // Accessing an element at a specific index takes constant time.
    cout << "Accessing element at index 2: " << arr[2] << endl;
    cout << "Operations: 1 (constant)" << endl;
}

// O(n) - Linear time
// Example: A simple loop that iterates through an array.
void linearTimeExample(int arr[], int n) {
    cout << "\nO(n) - Linear Time Example\n";
    int sum = 0;
    int counter = 0;  // To count the number of operations
    // Looping through the array takes linear time.
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        counter++;
    }
    cout << "Sum of array elements: " << sum << endl;
    cout << "Operations: " << counter << " (linear)" << endl;
}

// O(log n) - Logarithmic time
// Example: Reducing a number by half repeatedly.
void logarithmicTimeExample(int n) {
    cout << "\nO(log n) - Logarithmic Time Example\n";
    int steps = 0;
    int counter = 0;  // To count the number of operations
    // Each iteration divides the number by 2, reducing the problem size.
    while (n > 1) {
        n /= 2;
        steps++;
        counter++;
    }
    cout << "Number of steps to reduce to 1: " << steps << endl;
    cout << "Operations: " << counter << " (logarithmic)" << endl;
}

// O(n^2) - Quadratic time
// Example: Nested loops to compare elements (e.g., bubble sort simplified).
void quadraticTimeExample(int n) {
    cout << "\nO(n^2) - Quadratic Time Example\n";
    int counter = 0;  // To count the number of operations
    // Simple nested loop
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << i << "," << j << ") ";
            counter++;
        }
        cout << endl;
    }
    cout << "Operations: " << counter << " (quadratic)" << endl;
}

// O(2^n) - Exponential time
// Example: Recursive Fibonacci function
int exponentialTimeExample(int n, int &counter) {
    counter++;  // Count each function call as an operation
    // Base case: O(1) operation
    if (n <= 1) return n;
    // Recursive Fibonacci, each call spawns two more calls, hence O(2^n).
    return exponentialTimeExample(n - 1, counter) + exponentialTimeExample(n - 2, counter);
}

// O(n!) - Factorial time
// Example: Generating all permutations of a string (simplified to recursion)
void factorialTimeExample(int n) {
    cout << "\nO(n!) - Factorial Time Example\n";
    int factorial = 1;
    int counter = 0;  // To count the number of operations
    // Simple loop to calculate factorial
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        counter++;
        cout << "Factorial of " << i << " is " << factorial << endl;
    }
    cout << "Operations: " << counter << " (factorial)" << endl;
}

int main() {

    // O(1) - Constant Time Example
    constantTimeExample();

    // O(n) - Linear Time Example
    int arr[] = {1, 2, 3, 4, 5};
    linearTimeExample(arr, 5);

    // O(log n) - Logarithmic Time Example
    logarithmicTimeExample(16);  // Example: dividing by 2 each step

    // O(n^2) - Quadratic Time Example (Nested Loops)
    quadraticTimeExample(3);  // Example with a 3x3 grid

    // O(2^n) - Exponential Time Example (Fibonacci)
    cout << "\nO(2^n) - Exponential Time Example (Fibonacci)\n";
    int fibN = 5;
    int fibCounter = 0;
    cout << "Fibonacci of " << fibN << ": " << exponentialTimeExample(fibN, fibCounter) << endl;
    cout << "Operations: " << fibCounter << " (exponential)" << endl;

    // O(n!) - Factorial Time Example
    factorialTimeExample(4);  // Example: calculating factorial up to 4!

    return 0;
}
