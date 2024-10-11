def bubble_sort(lst): #max no. of swaps is n(n-1)/2
    sorted = False
    length = len(lst) -1 #since we'll be testing lst[i+1]
    
    while not sorted:
        sorted = True
        for i in range(length):
            if lst[i] > lst[i+1]:
                sorted = False
                lst[i], lst[i+1] = lst[i+1], lst[i]
    return lst

lst = [1,3,-2,70,9]
print(lst)
print(bubble_sort(lst))
