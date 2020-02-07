def trap(height):
        if not height:
            return 0
        height.append(0)
        stack = []
        result = 0
        for i in range(len(height)):
            while stack and height[stack[-1]] < height[i]:
                baseline=height[stack.pop()]
                if not stack:
                    break
                leftboundry = stack[-1]
                high = min(height[leftboundry], height[i])-baseline
                width = i-(leftboundry + 1)
                result += high * width
            stack.append(i)
        return result

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


