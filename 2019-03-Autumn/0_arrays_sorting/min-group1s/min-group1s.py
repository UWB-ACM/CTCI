from __future__ import print_function

def min_swaps_naive(array):
    # count total number of 1's
    total_count = 0
    for num in array:
        if num == 1:
            total_count += 1
    
    max_count_in_subarray = 0
    # iterate thru `len(array) - total_count` subarrays
    for i in range(len(array) - total_count + 1):
        
        one_count = 0

        # count number of 1's in a subarray
        for j in range(total_count):
            if array[i + j] == 1:
                one_count += 1
        
        if one_count > max_count_in_subarray:
            max_count_in_subarray = one_count

    # count of 0's is the actual answer
    return total_count - max_count_in_subarray

def min_swaps_efficient(array):
    # count total number of 1's
    total_count = 0
    for num in array:
        if num == 1:
            total_count += 1

    running_count = 0
    # need to count the first subarray
    for i in range(total_count):
        if array[i] == 1:
            running_count += 1
    
    max_count_in_subarray = running_count
    
    # sliding window
    left = 0
    right = total_count
    while right < len(array):

        if array[left] == 1:
            running_count -= 1
        if array[right] == 1:
            running_count += 1

        if running_count > max_count_in_subarray:
            max_count_in_subarray = running_count
        left += 1
        right += 1

    return total_count - max_count_in_subarray

def min_swaps_pythonic(array):
    total_count = array.count(1)
    running_count = array[:total_count].count(1)
    max_count_in_subarray = running_count
    for left, right in zip(array, array[total_count:]):
        running_count += right - left
        max_count_in_subarray = max(max_count_in_subarray, running_count)
    return total_count - max_count_in_subarray

testcases = [
    [1,0,1,0,1],
    [1,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1],
    [0,0,0,0,0,0,0,0,0,1],
    [1,0,0,0,0,0,0],
    [1,1,1,1,1,1,0],
    [0,1,1,1,1,1,1],
    [],
    [1],
    [0],
    [0,0],
    [1,0],
    [0,1],
    [1,1],
    [1,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1]
]

print("Testing all 3 versions of the min_swaps function")

for test in testcases:
    print("Case:", test)
    naive = min_swaps_naive(test)
    efficient = min_swaps_efficient(test)
    pythonic = min_swaps_pythonic(test)
    print("Results: ", end="")
    print("Naive: " + str(naive), 
          "Efficient: " + str(efficient), 
          "Pythonic: " + str(pythonic), sep=", ")