def bubble_sort(lst):  # max no. of swaps is n(n-1)/2
    sorted = False
    last_index = len(lst) - 1  # since we'll be testing lst[i+1]
    
    while not sorted:
        sorted = True
        for current_index in range(last_index):
            if lst[current_index] > lst[current_index + 1]:
                sorted = False
                lst[current_index], lst[current_index + 1] = lst[current_index + 1], lst[current_index]
    return lst

lst = [1, 5, 3, 2, 4]
print(lst)
print(bubble_sort(lst))
