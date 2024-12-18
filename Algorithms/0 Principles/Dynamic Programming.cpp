#include <iostream>
#include <vector>
using namespace std;

/*
    Dynamic Programming (DP) is an optimization technique used to solve problems by 
    breaking them into smaller overlapping subproblems and storing their results 
    to avoid redundant computations.

    To solve DP problems, we first write a recursive solution in a way that there are overlapping subproblems in the recursion tree (the recursive function is called with same parameters multiple times)
    
    To make sure that a recursive value is computed only once (to improve time taken by algorithm), we store results of the recursive calls.

    The idea is to simply store the results of subproblems so that we do not have to re-compute them when needed later. This simple optimization typically reduces time complexities from exponential to polynomial. 

    There are two ways to store the results:
        1. Memoization (Top-Down): Recursive approach with results stored in a cache.
        2. Tabulation (Bottom-Up): Iterative approach that builds the solution from the ground up.

    Common Applications:
        - Fibonacci Sequence
        - Knapsack Problem
        - Diff Utility (Longest Common Subsequence)
        - Shortest Path Problems (e.g., Bellman–Ford, Floyd-Warshall)
        - Edit Distance
        - Matrix Chain Multiplication

    Pros:
        - Reduces time complexity significantly by avoiding redundant calculations.
        - Simplifies the design of algorithms for certain classes of problems.

    Cons:
        - Higher space complexity due to storage of subproblem results.
        - Requires understanding of problem structure to define subproblems effectively.
*/

/* 
    Fibonacci Functions 

    The Fibonacci sequence is a series of numbers where each number
    is the sum of the two preceding ones, starting from 0 and 1.
*/

// Tabulated Fibonacci (Bottom-Up)
int fibonacciTab(int n) {
    // Base case: The first two Fibonacci numbers are 0 and 1.
    if (n <= 1)
        return n;

    // Initialize a vector to store Fibonacci numbers up to n.
    vector<int> dp(n + 1);

    // Define the base cases in the table.
    dp[0] = 0; // Fibonacci(0) = 0
    dp[1] = 1; // Fibonacci(1) = 1

    // Fill the table iteratively from Fibonacci(2) to Fibonacci(n).
    for (int i = 2; i <= n; i++) {
        // Each Fibonacci number is the sum of the two preceding numbers.
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number from the table.
    return dp[n];
}

// Recursive Fibonacci with Memoization
int fibonacciMemo(int n, vector<int> &memo) {
    // Base case: The first two Fibonacci numbers are 0 and 1.
    if (n <= 1)
        return n;

    // If the Fibonacci number for 'n' has already been calculated,
    // retrieve it from the memoization table to save computation.
    if (memo[n] != -1)
        return memo[n];

    // Otherwise, compute the Fibonacci number recursively and store the result in the table.
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);

    // Return the computed Fibonacci number for 'n'.
    return memo[n];
}

/*
    Factorial Functions 
*/

// Factorial using Tabulation (Bottom-Up)
int factorialTabulation(int n) {
    // Handle invalid input (negative numbers).
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1;
    }

    // Create a DP table to store results.
    vector<int> dp(n + 1);
    dp[0] = 1; // Base case: 0! = 1

    // Fill the DP table iteratively.
    for (int i = 1; i <= n; i++) {
        dp[i] = i * dp[i - 1];
    }

    // Return the factorial of n.
    return dp[n];
}

// Factorial using Memoization (Top-Down)
int factorialMemoization(int n, vector<int>& memo) {
    // Handle invalid input (negative numbers).
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1;
    }

    // Base case: 0! = 1, 1! = 1
    if (n == 0 || n == 1)
        return 1;

    // If the result is already calculated, return it.
    if (memo[n] != -1)
        return memo[n];

    // Store the result in memo and return.
    memo[n] = n * factorialMemoization(n - 1, memo);
    return memo[n];
}

int main() {

    // Fibonacci Example
    cout << "Dynamic Programming: Fibonacci Sequence\n";
    int n = 10;

    // Tabulation
    cout << "Fibonacci (Tabulation, n=10): " << fibonacciTab(n) << endl;

    // Memoization
    vector<int> fibonacciMemoTable(n + 1, -1);
    cout << "Fibonacci (Memoization, n=10): " << fibonacciMemo(n, fibonacciMemoTable) << endl;

    // Factorial Example
    n = 5;
    cout << "\nDynamic Programming: Factorial Calculation\n";

    // Tabulation
    cout << "Factorial of " << n << " (Tabulation): " << factorialTabulation(n) << endl;

    // Memoization
    vector<int> factorialMemoTable(n + 1, -1);
    cout << "Factorial of " << n << " (Memoization): " << factorialMemoization(n, factorialMemoTable) << endl;

    return 0;
}
