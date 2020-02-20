<!-- Don't remove -->
<a name="top"/>

# Graphs

Problems and solutions for Graphs session on February 21, 2020.

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

### 1. Telephone Strangers

Source: Lizzy, inspired by multigraph definition in [Rosen et. al.](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen-ebook/dp/B07FF9DY66)

#### Scenario

You are given a map m which represents a graph of phone calls between distinct numbers. Each entry in m maps a phone number to an array of all individual phone calls on that line from the previous 30 days.

Find all the pairs of phone numbers which didn't have any calls placed to each other.

Additional info:

- You may assume that map entries are reflexive; if a call between Line A and Line B is placed, the map entry for Line B will contain Line A, and vice versa.
- A phone number cannot place a call to itself.

#### Example Input

We shorten phone numbers in the examples for readability.

**Example 1**
```
Input:   m = { '206': [], '940': ['425'], '425': ['940'] }
Output:  [('206', '940'), ('206', '425')]
```
Reasoning: '206' did not speak to anyone on the phone, and is therefore a stranger to '425' and '940'. This produces the two pairs of telephone strangers.

**Example 2**
```
Input:   m = { '1': ['2', '3', '4'], '2': ['1', '4'], '3': ['1'], '4': ['1', '2'] }
Output:  [('2', '3'), ('3', '4')]
```
'1' had phone calls with all other phone numbers in the map. '2' and '4' are missing phone calls with '3', forming two pairs of telephone strangers.

**Example 3**
```
Input:   m = { 'a': ['b', 'b', 'b', 'b', 'c'], 'b': ['a', 'a', 'c', 'a', 'a'], 'c': ['b', 'a'] }
Output:  []
```
'a' and 'b' had many calls with each other (perfectly legal in this scenario), and both 'a' and 'b' had calls with 'c'. There are no strangers in this scenario.

#### Function Signature

**D**esign **I**t **Y**ourself

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

### 1. Telephone Strangers

Source: Lizzy & Erica

#### Naive/Simple Solution

If two numbers are telephone strangers, _they will not have any edges between them_. So, we develop an algorithm which identifies those cases.

We iterate through each graph node (aka telephone number) and check for the presence of all other vertices in the number's call list. If any vertex is missing from the list, we have found a pair of vertices with no edges, and these nodes are strangers to each other.

We assemble pairs of strangers and return the resulting array/list/vector.

```c++
std::pair<std::string, std::string> Helper(std::set<Vertex *> InCallHistory, Vertex *Curr)
{
    for (auto I : Curr->returnCallsMade())
    {
        auto Temp = InCallHistory.find(I->returnCalled()); 
        if(Temp == InCallHistory.end())
        {
            continue;
        }

        InCallHistory.erase(I->returnCalled());
    }

    std::vector<Vertex *> Temp;
    for (auto I : InCallHistory)
    {
        Temp.push_back(I);
    }
    if (Temp.size() > 1) {
        auto Foo = std::make_pair(Temp[0]->returnNumber(), Temp[1]->returnNumber());
        return Foo;
    }
    return std::make_pair("", "");
}

std::vector<std::pair<std::string, std::string>>
FindStrangers(Graph *PhoneHistory)
{
    std::vector<std::pair<std::string, std::string>> StrangerPairs;
    std::set<Vertex *> PrevCallStack;
    auto Numbs = PhoneHistory->returnPhoneNumbers();

    for (auto I : Numbs)
    {
        PrevCallStack.insert(I.second);
    }

    for (auto I : Numbs)
    {
        if(I.second->returnCallsMade().empty())
        {
            continue;
        }
        StrangerPairs.push_back(Helper(PrevCallStack, I.second));
    }

    return StrangerPairs;
}
```



#### Testing The Solutions OR Driver For Solution

The [C++](./TelephoneStrangers/TelephoneStrangers.cpp) and [Python](./TelephoneStrangers/strangers.py) solutions are in the repository.

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
