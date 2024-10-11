/*

Space Complexity refers to the total amount of memory an algorithm uses during its execution. It consists of two parts: the memory needed to store the input data and any extra memory (referred to as auxiliary space) that the algorithm requires.

The space complexity of an algorithm is a function of the input size and is often expressed using Big O notation, such as O(n), O(nlog⁡n) ,O(2^n), etc., where nnn represents the size of the input influencing memory usage.

Auxiliary Space is the extra or temporary memory used by the algorithm, excluding the input data itself. Therefore: 
    Space Complexity = Auxiliary Space + Space used for input

This means space complexity accounts for both the memory needed to store input and any additional space required by the algorithm for its internal operations (e.g., temporary arrays, recursion stack space).

In general, an efficient algorithm should minimize space complexity. However, reducing memory usage does not always mean the algorithm will execute faster, as some algorithms may trade time for space. The goal is to find the best balance between time and space efficiency.

References:
    https://www.faceprep.in/data-structures/space-complexity/

*/

#include <iostream>
using namespace std;

int main(void) {
    
    // In this block, we use three integer variables (a, b, and c), each of size 4 bytes (assuming standard 4-byte integers).
    // The total memory usage is constant and doesn't depend on any input. This is why the space complexity is O(1).
    int a = 5, b = 5, c;
    c = a + b;
    cout << c << endl;

    // Here, we dynamically allocate an array of size n, which occupies 4 * n bytes (assuming 4 bytes per integer). 
    // We also have three additional integer variables (n, i, sum), each taking 4 bytes.
    // Therefore, the total space usage is 4n + 12 bytes.
    // Since n is the largest term in this equation, the overall space complexity is O(n) (linear).
    int n, i, sum = 0;
    cin >> n;

    // Dynamically allocate an array of size n
    int* dynArr = new int[n];
    for(i = 0; i < n; i++) {
        cin >> dynArr[i];
        sum += dynArr[i];
    }

    // This block demonstrates dynamic memory allocation.
    // The space complexity is still O(n), as we're dynamically allocating memory for 'n' integers on the heap.
    cout << "Sum with dynamic array: " << sum << endl;

    // Clean up the dynamically allocated memory.
    delete[] dynArr;

    return 0;
}
