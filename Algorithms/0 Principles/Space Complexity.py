# Space Complexity

def main():
    # In this block, we use three integer variables (a, b, and c).
    # The total memory usage is constant and doesn't depend on any input.
    # This is why the space complexity is O(1).
    a = 5
    b = 5
    c = a + b
    print(f"Sum of a and b is: {c}")

    # Here, we demonstrate dynamic memory allocation.
    # We prompt the user to enter the size of the array.
    n = int(input("Enter the size of the dynamic array (n): "))
    
    # We use a list of size n, which occupies space proportional to n.
    # Therefore, the total space usage is proportional to n.
    # Space complexity is O(n) (linear).
    dyn_arr = [0] * n  # Dynamically allocating memory for n integers
    total_sum = 0

    # Filling the dynamically allocated array
    for i in range(n):
        dyn_arr[i] = int(input(f"Enter element {i + 1}: "))
        total_sum += dyn_arr[i]

    print(f"Sum of elements in dynamic array: {total_sum}")

    # Note: In Python, memory management is handled automatically, 
    # and there's no need to explicitly free memory like in C++.
    
if __name__ == "__main__":
    main()
