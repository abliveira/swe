def merge(left, right):
    """Merge two sorted lists into a single sorted list."""
    if not left or not right:
        return left or right
    
    result = []
    i, j = 0, 0

    # Merge the two parts into result[]
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Extend the result with any remaining elements
    result.extend(left[i:] or right[j:])

    return result

def merge_sort(arr):
    """Sort the array using the merge sort algorithm."""
    if len(arr) < 2:
        return arr

    mid = len(arr) // 2  # Calculate the midpoint safely
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)

# Example usage
a = [31, 4, 88, 1, 4, 2, 42]
print(merge_sort(a))
