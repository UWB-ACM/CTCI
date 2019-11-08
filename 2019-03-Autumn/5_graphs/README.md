<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

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

### 1. Find Mutual Friends 

Source: Lizzy

#### Scenario

Imagine a Facebook-esque social network that is represented by a graph. Each vertex represents a person's account, 
and the edges between vertices represent friend status.

Write a method that counts the number of mutual friends between two people.

You can assume the `Vertex` class/struct is defined as follows:

```
class Vertex {
    string name;
    set<Vertex> friends;
}
```

#### Function Signature

```java
int findMutualFriends(Vertex p1, Vertex p2) {
    // your code here
}
```

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

### 1. Find Mutual Friends

Source: Tom, Lizzy, Google 

#### Naive/Simple Solution

The solution for this problem is to find the intersection of both input 
vertices set of friends. This solution copies one input vertex's set of friends into a `HashSet`,
calls `retainAll` method on this set, which iterates through the set while checking
if the next node is contained in the other input vertex's set of friends. If it is not, the `retainAll`
method will remove the node the iterator is pointing to and move to the next, leaving only common nodes (or mutual
friends) of both vertices. At this point, to get the count of mutual friends, access the size of the modified set
where vertex1 intersects vertex2. 

The other thing to note is that this implementation's Vertex class scopes the `Set` members to private, hence the 
`getFriends()` method call.

Java Implementation:
```java
int findMutualFriends(Vertex p1, Vertex p2) {
        Set<Vertex> intersection = new HashSet<>(p1.getFriends());
        intersection.retainAll(p2.getFriends());
        return intersection.size();
    }
```

#### Driver For Solution

[The java solution is here.](./find_mutual_friends/mutual.java)

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
