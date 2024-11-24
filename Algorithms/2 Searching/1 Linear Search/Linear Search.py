def search(x, my_list):
    for k in range(len(my_list)):
        if my_list[k] == x:
            return k
    return -1
    
nums = [5, 2, 42, 6, 1, 3, 2]
print(search(42, nums))