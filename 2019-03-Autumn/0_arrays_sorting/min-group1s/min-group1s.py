def min_swaps_naive(l):
    # count total number of 1's
    total_count = 0
    for num in l:
        if num == 1:
            total_count += 1
    
    max_one_count = 0
    # iterate thru `len(l) - total_count` subarrays
    for i in range(len(l) - total_count + 1):
        
        one_count = 0

        # count number of 1's in a subarray
        for j in range(total_count):
            if l[i + j] == 1:
                one_count += 1
        
        if one_count > max_one_count:
            max_one_count = one_count

    # count of 0's is the actual answer
    return total_count - max_one_count

def min_swaps_efficient(l):
    # count total number of 1's
    total_count = 0
    for num in l:
        if num == 1:
            total_count += 1

    running_count = 0
    # need to count the first subarray
    for i in range(total_count):
        if l[i] == 1:
            running_count += 1
    
    max_one_count = running_count
    
    # sliding window
    left = 0
    right = total_count
    while right < len(l):

        if l[left] == 1:
            running_count -= 1
        if l[right] == 1:
            running_count += 1

        if running_count > max_one_count:
            max_one_count = running_count
        left += 1
        right += 1

    return total_count - max_one_count

def min_swaps_pythonic(l):
    total_count = l.count(1)
    running_count = l[:total_count].count(1)
    max_one_count = running_count
    for x,y in zip(l, l[total_count:]):
        running_count += y - x
        max_one_count = max(max_one_count, running_count)
    return total_count - max_one_count

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

for test in testcases:
    print("Case: ", test, sep="")
    print(min_swaps_naive(test), 
          min_swaps_efficient(test), 
          min_swaps_pythonic(test), sep=", ")