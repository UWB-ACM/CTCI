<!-- Don't remove -->
<a name="top"/>

# Intervals

***Problems and solutions for Intervals session on November 6, 2020.***

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

### 1. Insert Interval

Source: [LeetCode](https://leetcode.com/problems/insert-interval/)

#### Scenario

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

#### Example Input 1

**Input:** `intervals = [[1,3],[6,9]], newInterval = [2,5]`

**Output:** `[[1,5],[6,9]]`

**Explanation:** 
The new interval overlaps the two existing intervals. This will merge the new interval with the `[1,3]` interval, changing it to `[1,5]`.

#### Example Input 2

**Input:** `intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]`

**Output:** `[[1,2],[3,10],[12,16]]`

**Explanation:** 
Because the new interval `[4,8]` overlaps with `[3,5],[6,7],[8,10]`.

#### Function Signature

**C++:** `vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)`

**Java:** ` public int[][] insert(int[][] intervals, int[] newInterval)`

**Python:**  ` def insert(self, intervals, newInterval)`

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 1. Insert Interval

Source: [LeetCode](https://leetcode.com/problems/insert-interval/)

#### Greedy algorithm

The idea of greedy algorithm is to pick the locally optimal move at each step, that will lead to the globally optimal solution.

Since we can assume the intervals are already sorted, a straightforward one-pass strategy could be implemented in three steps.

1 . Add to the output all the intervals starting before `newInterval`.
2 . Add to the output `newInterval`, merge it with the last added interval if needed.
3 . Add the next intervals one by one. Merge with the last added interval if the current interval starts before the last added interval.

```c++
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	//First check if the intervals vector is empty
	if (intervals.size() == 0 ) {
		return {newInterval};
	}
	
	//Start time of the new interval
	int newStart = newInterval[0];
	//End time of the new interval
	int newEnd = newInterval[1];
	//Index to iterate through intervals
	int i = 0;
	//Vector of vectors to return
	vector<vector<int>> res;
	int size = intervals.size();
	
	//Add the intervals whose starting time is less than the new interval starting time
	//Into the res vector
	while (i < size && newStart > intervals[i][0]) {
		res.push_back(intervals[i++]);
	}   
	//We will use this interval vector as intervals holder
	vector<int> interval(2);
	
	//If there is no overlap, then add the new interval 
	//An overlap happens if the end time of the last interval in res is greater than the new interval start time
	if (res.size() == 0 || res[res.size() - 1][1] < newStart) {
		res.push_back(newInterval);
	} else {
		//Otherwise, if there is an overlap, merge with the last interval in res
		vector<int> temp = res[res.size() - 1];
		res.pop_back();
		interval[0] = temp[0];
		interval[1] = max(temp[1],newEnd);
		res.push_back(interval);
	}
	
	// Add new intervals, and merge with newInterval if the intervals overlap 
	while (i < size) {
		vector<int> temp = intervals[i++];
		//Start time of the temp interval
		int start = temp[0];
		//End time of the temp interval
		int end = temp[1];
		
		//Check for overlap
		//If the start time of temp is greater than the end time of the last interval in res
		//It means there is no overlap
		if (res[res.size() - 1] [1] < start){
			res.push_back(temp);
		}else{
			//Else we need to update the last interval in res
			//To have the latest end time between the current end time
			//And temp end time
			interval = res[res.size() - 1];
			res.pop_back();
			interval[1] = max(interval[1], end);
			res.push_back(interval);
		}
		
	}
	return res;
}
```

Time complexity: When implementing greedy algorithms, we usually need to figure out a way to sort the data,
this step usually leads to a time complexity of O(N logN). Then after sorting the data, we need to iterate 
through it, which takes O(N) time. 

In this case, we have a well-sorted inpit that does not need to be sorted, allowing us to perform the greedy
solution in O(N) time complexity.

Space complexity: O(N) to keep the output.

#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

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
