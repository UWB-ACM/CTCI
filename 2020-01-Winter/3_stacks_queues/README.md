<!-- Don't remove -->
<a name="top"/>

# Stacks & Queues

Problems and solutions for Stacks & Queues session on February 7, 2020.

### Table of Contents

* [Problems](#problems)
  * [1](#p1)
  * [2](#p2)
  * [3](#p3)
* [Solutions](#solutions)
  * [1](#s1)
  * [2](#s2)
  * [3](#s3)

<!-- Don't remove -->
<a name="problems"/>

## Problems

<a name="p1"/>

### 1. ValidParenthses

Source: https://leetcode.com/problems/valid-parentheses/

#### Scenario

Problem Statement:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct logical order.
Note that an empty string is also considered valid.

#### Example Input
```
"()"
"()[]{}"
"(]"
"([)]"
"{[]}"
```

#### Example Output
```
true
true
false
false
true
```

#### Function Signature

```c++
public:
    bool isValid(string s) {
        
    }
```

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Recent Counter

Source: https://leetcode.com/problems/number-of-recent-calls/

#### Scenario

Problem Statement:
Write a class named `RecentCounter` to count recent requests. It has only one method: `ping(int t)`, where `t` represents some time in milliseconds.

Return the **number of pings** that have been made from 3000 milliseconds ago until now.
Any ping from time `t-3000` (3000 milliseconds ago) to `t` (now, when this function was called) will count.

It is guaranteed that every call to ping uses a strictly larger value of `t` than before. Therefore, if the previous call to ping was made with `t=4500`, in the next call to ping it is guaranteed that `t > 4500`. It is also guaranteed that `t` will be a positive integer.


#### Example Input
```
[0]
[1000]
[2000]
[3000]
[4000]
[5000]
[6000]
[7000]
[8000]
[9000]
[10000]
```
Each number represents a separate call to `ping()`.

#### Example Output
```
[1]
[2]
[3]
[4]
[4]
[4]
[4]
[4]
[4]
[4]
[4]
```
Each number represents a separate return from `ping()`.

#### Function Signature
Example Java function signature:
```java
class RecentCounter {
    public RecentCounter() {
    }
    public int ping(int t) {
        // your code here
    }
}
```
Example Python function signature:
```
class RecentCounter:
    def __init__(self):
        # your code here
    def ping(self, t):
        # your code here
```

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Trapping Rain Water 

Source: [LeetCode](https://leetcode.com/problems/trapping-rain-water/)

#### Scenario

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

#### Example Input

![alt text](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png "Example")

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Input: [0,1,0,2,1,0,1,3,2,1,2,1] </br>
Output: 6

#### Function Signature

C++:

```c++
public:
    int trap(vector<int>& height) {
        # your code here
    }
```

Python:

```python
def trap(self, height):
    # your code here
```

Java:

```java
public int trap(int[] height) {
       # your code here 
    }
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)


<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. ValidParentheses

Source: https://leetcode.com/problems/valid-parentheses/

#### Solution

```c++
bool isValid(string s) {
      stack<char> st;

      for(int i=0;i<s.length();i++)
      {
          if(s[i] == '(' || s[i] == '{' || s[i] == '[')
              st.push(s[i]);
          // Can't be empty at this point...
          if(st.empty())
              return false;
          if(s[i] == ')')
          {
              int x = st.top();
              st.pop();
              if(x != '(')
                  return false;
          }
          else if(s[i] == '}')
          {
              int x = st.top();
              st.pop();
              if(x != '{')
                  return false;
          }
          else if(s[i] == ']')
          {
              int x = st.top();
              st.pop();
              if(x != '[')
                  return false;
          }
      }    
     return st.empty();
  }
  ```

#### Testing The Solutions OR Driver For Solution

```console
$ g++ ValidParentheses.cpp && ./a.out
test0 = (). Valid?: 1
test1 = ()[]{}. Valid?: 1
test2 = (]. Valid?: 0
test3 = {[]}. Valid?: 1
test4 = . Valid?: 1
test5 = abc[]. Valid?: 0
```

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Recent Counter

Source: https://leetcode.com/problems/number-of-recent-calls/solution/

#### Naive/Simple Solution
**Time Complexity**: O(n) where N is the number of times `ping()` is called.

**Space Complexity:** O(n) where N is the number of times `ping()` is called. In this case, the maximum size of the queue is bounded at 3001 elements.

Java Solution:
```java
class RecentCounter{
    //This is one way of making a FIFO Queue in Java
    Queue<Integer> queue = new LinkedList<>();

    //The ping function.
    //Calling this function requires passing in the time t in milliseconds
    public int ping(int t){
        //First, we eneueue the new time into the end of the queue
        queue.add(t);

        //Now we loop through the queue and dequeue from the front
        //any pings that happened more that 3000 seconds ago
        for(int i = 0; i < queue.size(); i++){
            if(queue.peek() < t-3000){
                queue.remove();
            }
        }

        //Since the problem statement wants the number of pings in
        //the previous 3000 milliseconds, we can now simply return
        //the number of elements in the queue
        return queue.size();
    }
}
```

Python Solution:
```python
class RecentCounter:
    #This queue is a Python list
    #In this problem, we treat it like a FIFO Queue
    def __init__(self):
        self.queue = []

    #The ping function. The self is implicit, so calling
    #this function requires passing in the time t in milliseconds
    #self is like "this" in Java
    def ping(self, t):
        #First, we eneueue the new time into the end of the queue
        self.queue.append(t)

        #Now we loop through the queue and dequeue from the front
        #any pings that happened more that 3000 seconds ago
        while self.queue and self.queue[0] < t - 3000:
            self.queue.pop(0)
            
        #Since the problem statement wants the number of pings in
        #the previous 3000 milliseconds, we can now simply return
        #the number of elements in the queue
        return len(self.queue)
```

#### Testing The Solutions OR Driver For Solution

[**Java Solution**](./3_stacks_queues/recent_counter/recent_counter_java.java)

[**Python Solution**](./3_stacks_queues/recent_counter/recent_counter_python.py)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Trapping Rain Water 

Source: [LeetCode](https://leetcode.com/problems/trapping-rain-water/)

#### Solution

There are multiple ways to solve this problem; this writeup will focus on 
a solution which uses stacks.

We keep a stack and iterate over the array. We add the index of the bar 
to the stack if bar is smaller than or equal to the bar at top of stack, 
which means that the current bar is bounded by the previous bar in the 
stack. 

If we found a bar longer than that at the top, we are sure that the bar 
at the top of the stack is bounded by the current bar and a previous bar 
in the stack, hence, we can pop it and add resulting trapped water to `ans`.


```python
def trap(self, height):
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
 ```
 

#### Driver For Solution

The solution code is [in the repository](./TrappingRainWater/TrappingRainWater.py).


It produces the following output:

```console
$ python TrappingRainWater.py
Test Begins
Test 1
[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
6
Test 2
[0, 3, 2, 1, 0, 4, 6, 2, 0, 1, 2, 3, 1]
13
```

<!-- Don't remove -->
Go to [Top](#top)
