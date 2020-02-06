def trap(height):
    s = 0
    l, r = 0, len(height)-1
    while l < r:
        i = 1
        if height[l] < height[r]:
            while height[l] > height[l+i]:
                s += height[l] - height[l+i]
                i += 1
            l += i
        else:
            while height[r] > height[r-i]:
                s += height[r] - height[r-i]
                i += 1
            r -= i
    return s

def main():
    print("Test Begins")
    print("Test 1")
    arr1 = [0,1,0,2,1,0,1,3,2,1,2,1]
    test1 = trap(arr1)
    print(arr1)
    print(test1)
    print("Test 2")
    arr2 = [0,3,2,1,0,4,6,2,0,1,2,3,1]
    print(arr2)
    print(trap(arr2))

if __name__ == '__main__':
    main()


