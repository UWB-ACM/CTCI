# Intervals

## Table of Contents

### Problems
1. [Merge Intervals](https://leetcode.com/problems/merge-intervals/) (Medium)
2. [Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/) (Medium)
3. [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)(Medium)

## Problem 1


### Title:
[Merge Intervals](https://leetcode.com/problems/merge-intervals/) (Medium)

### Description:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Example 1:
**Input** intervals = [[1,3],[2,6],[8,10],[15,18]]
**Output** [[1,6],[8,10],[15,18]]
**Explanation:** Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

<br>
<br>
<br>

## Problem 2

### Title:
[Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/) (Medium)

### Description:
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

### Example 1:
**Input** slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
**Output** [60,68]


<br>
<br>
<br>

## Problem 3

### Title:
[Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)(Medium)

### Description:
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

### Example 1:
**Input** intervals = [[1,2],[2,3],[3,4],[1,3]]
**Output** 1
**Explanation** [1,3] can be removed and the rest of the intervals are non-overlapping.

<br>
<br>
<br>


# Solutions

## Solution 1

### Greedy Solution

**Approach**
1. Sort the interval list in in ascending order by start time.
2. Compare the prev time with the current time (prev = 0, current = 1)
3. If the finish time of prev intervals is larger or equal to the start time of current intervals, it means that current time intervals is overlapping.
4. Set new time intervals so that prev intervals and current intervals is not overlapping
5. Compare the finish time of prev and current intervals, we want the largest value so we use Math.max to fing the largest value between those intervals. and set the value as the new finish time.
6. Compare the start time of prev and current intervals, we want the smallest value in the start time so we use Math.min. and set the value as the new start time.
7.If the finish time of prev intervals is smaller than the next start time of current intervals, it means that the current intervals is not overlapping. and the prev intervals is good to go.
8. merged the prev intervlas to the answer, and move prev to the next which is the current.

```
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        ArrayList<int[]> merged = new ArrayList<>();
        
        int start = 0;
        int end = 1;
        
        int[] prev = intervals[0];
        for(int i = 1; i < intervals.length; i++) {
            int[] current = intervals[i];
            if(prev[end] >= current[start]) {
                prev[end] = Math.max(prev[end], current[end]);
                prev[start] = Math.min(prev[start], current[start]);
            } else {
                merged.add(prev);
                prev = current;
            }
        }
        merged.add(prev);
        return merged.toArray(new int[merged.size()][]);
    }
}
```
<br>
<br>

## Solution 2

### Heap (use priority queue)

**Approach**
1. Initialize a heap timeslots and push time slots that last longer than duration into it.
2. Iterate until there's only one time slot remaining in timeslots:
    - Pop the first time slot [start1, end1] from timeslots.
    - Retrieve the next time slot [start2, end2], which is the current top element in timeslots.
    - If we find end1 >= start2 + duration, because start1 <= start2, the common slot is longer than duration and we can return it.
3. If we don't find the common slot that is longer than duration, return an empty array.

```
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        PriorityQueue<int[]> timeslots = new PriorityQueue<>((slot1, slot2) -> slot1[0] - slot2[0]);

        for (int[] slot: slots1) {
            if (slot[1] - slot[0] >= duration) timeslots.offer(slot);
        }
        for (int[] slot: slots2) {
            if (slot[1] - slot[0] >= duration) timeslots.offer(slot);
        }

        while (timeslots.size() > 1) {
            int[] slot1 = timeslots.poll();
            int[] slot2 = timeslots.peek();
            if (slot1[1] >= slot2[0] + duration) {
                return new ArrayList<Integer>(Arrays.asList(slot2[0], slot2[0] + duration));
            }
        }
        return new ArrayList<Integer>();
    }
}
```
<br>
<br>

## Solution 3

### Greedy approach
1. Sort the interval list in in ascending order by start time.
2. Set the end value as the end time of 1st intervals.
3. set the current at 1. and iterate trough the arrays
4. compare the end value to the start time of current intervals.
5. If the end time is larger than the start of current intervals, it mean the time was overlapped.
6. find the smallest end using Math.min between the end and current finish time. and add it to count because it overlapped.
7. if not/ else, change the value of the end to the current finish time. 

**Approach**

```
class Solution {
	public int eraseOverlapIntervals(int[][] intervals) {

		int count = 0;
		if (intervals.length == 0) {
			return count;
		}

		Arrays.sort(intervals, (a,b) -> (a[0] - b[0]));
		count = 0;
		int end = intervals[0][1];

		for (int i = 1; i < intervals.length; i++) {
			if(end > intervals[i][0]) {
				end = Math.min(end, intervals[i][1]);
				count++;
			} else {
				end = intervals[i][1];
			}		
        }

		return count;
	}
}
```
<br>
<br>
