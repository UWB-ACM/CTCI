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

### 1. Lonely on Twitter :bird:

Source: Lizzy

#### Scenario

On Twitter, users can follow other users, but the other users do not have 
to follow the initiator back. In this problem, we want to find the 
loneliest Twitter user -- the account with the highest number of 
followed accounts who did not follow back.

You are given a collection of users, and each user has a collection of accounts 
they are following. This data structure represents the directed graph of a Twitter network. 
Find the user with the highest number of unreciprocated follows.

#### Example Input

Here's a simple example:

```
Input:
    - Mindy: [Mork]
    - Mork: [Mindy]
    - Orson: [Mork, Mindy]
Output: Orson
```

Orson follows both other users, but neither of them follow him. Orson 
is the loneliest user.

```
Input:
    - Peter: [Lois, Chris, Brian]
    - Lois: [Chris, Brian, Stewie]
    - Brian: [Stewie, Lois]
    - Meg: [Peter, Lois, Chris, Brian, Stewie]
    - Chris: [Peter, Lois, Brian]
    - Stewie: []
Output: Meg
```

Meg has followed 5 users, but none of them have reciprocated; she is by far the loneliest user.

#### Function Signature

**D**esign **I**t **Y**ourself. _Hint: what input data structures would be most helpful for this scenario?_

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

### 1. Lonely on Twitter :bird:

Source: Lizzy

#### Solution

We want to track how much lower the reciprocation of each follow 
is for each user. So, we inspect each user, and one by one, we 
inspect that user's followed list. We lookup that followed account 
and see if the user is in the followed account's set; if it is, 
the follow is reciprocated. If it is not, we subtract 1 from the 
differential.

<details>
<summary>See Python3 solution</summary>

```python3
def lonely(users: dict) -> str:
    # users is a dictionary with K:V of str:set
    if not users: return None

    # create differential
    diff = {}
    for user in users:
        diff[user] = 0
        for followed in users[user]:
            if user not in users[followed]: 
                diff[user] -= 1

    # transform differential data into a list of pairs
    result = [(user, count) for user, count in diff.items()]
    # sort list of pairs by differential, lowest to highest
    result.sort(key=lambda x: x[1])
    return result[0][0]
```

</details>

What is wrong with this solution, if anything?

<details>
<summary>What's wrong</summary>

1. This solution doesn't account for multiple users having the same 
   follower differential, and only takes the first available answer.
2. The manipulation of the differential data is not particularly 
   efficient in runtime, although the code is concise and readable. 
   The list comprehension has a time complexity of `O(N^2)` because 
   lists with appended items are rebuilt in each iteration. The sort 
   call has an optimal time complexity of `O(n log n)`.

</details>

#### Testing The Solution

See the [solution method](./lonely_twitter/solution.py) and [driver](./lonely_twitter/driver.py) containing tests.

<details>
<summary>Test output</summary>

```console
$ python3 driver.py
User graph:
{
         Bob :  {'Theo', 'Rachel', 'Frank', 'Sandy'}
         Sandy :  {'Sally', 'Theo'}
         Frank :  {'Sally', 'Rachel', 'Sandy', 'Theo'}
         Theo :  {'Sally', 'Bob'}
         Sally :  set()
         Rachel :  {'Sally'}
}
The loneliest user is Frank 

User graph:
{
         Mindy :  {'Mork'}
         Mork :  {'Mindy'}
         Orson :  {'Mindy', 'Mork'}
}
The loneliest user is Orson 

User graph:
{
         Peter :  {'Brian', 'Chris', 'Lois'}
         Lois :  {'Chris', 'Stewie', 'Brian'}
         Brian :  {'Stewie', 'Lois'}
         Meg :  {'Stewie', 'Brian', 'Peter', 'Lois', 'Chris'}
         Chris :  {'Brian', 'Peter', 'Lois'}
         Stewie :  set()
}
The loneliest user is Meg
```

</details>

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
