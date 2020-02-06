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

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. SOLUTION 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Recent Counter

Source: https://leetcode.com/problems/number-of-recent-calls/solution/

#### Naive/Simple Solution
**Time Complexity**: O(n) where N is the number of times `ping()` is called.

**Space Complexity:** O(n) where N is the size of the window. In this case, 3000.

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
    queue = []

    #The ping function. The self is implicit, so calling
    #this function requires passing in the time t in milliseconds
    #self is like "this" in Java
    def ping(self, t):
        #First, we eneueue the new time into the end of the queue
        self.queue.append(t)

        #Now we loop through the queue and dequeue from the front
        #any pings that happened more that 3000 seconds ago
        for t in self.queue:
            if(self.queue[0] < t-3000):
                self.queue.pop(0)

        #Since the problem statement wants the number of pings in
        #the previous 3000 milliseconds, we can now simply return
        #the number of elements in the queue
        return len(self.queue)
```

#### Testing The Solutions OR Driver For Solution

**Java Solution:** (./3_stacks_queues/recent_counter/recent_counter_java.java)

[**Python Solution**](./3_stacks_queues/recent_counter/recent_counter_python.py)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
