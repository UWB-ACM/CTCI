<!-- Don't remove -->
<a name="top"/>

# Linked Lists

Problems and solutions for Linked Lists session on January 24, 2020.

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

### 3. Linked List Duplicates

Source: Cracking The Code Interview Book, Chapter 2, Question 2.1

#### Scenario

Remove duplicated from an **unsorted** linked list of integers.
*Follow Up Question:* How would you solve this without a temporary buffer?

**Assume the Tail will NOT connect back to the Head. Meaning it is NOT circular.**

#### Function Signature

`RemoveDuplicatesWithBuffer(Node *Start);`

`RemoveDuplicatesWithoutBuffer(Node *Start)`

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

Source: Cracking the Code Interview Book, Chapter 2, Question 2.1

#### Solution 

With the Buffer: Use a set to keep track of what integers have been encountered.

```
void RemoveDuplicatesWithBuffer(Node *Start) {
  if (Start == nullptr || Start->GetNext() == nullptr) {
    return;
  }

  unordered_set<int> set;

  Node *Curr = Start;
  Node *Prev = nullptr;

  while (Curr != nullptr) {
    // Doesn't exist
    if (set.find(Curr->GetValue()) == set.end()) {

      set.insert(Curr->GetValue());
      Prev = Curr;
      Curr = Curr->GetNext();

    } else { // Exists

      Prev->SetNext(Curr->GetNext());
      delete Curr;
      Curr = Prev->GetNext();
    }
  }
}
```

Without a Buffer: Have a pointer/runner that iterates over the list to check for duplicates.

```
void RemoveDuplicatesWithoutBuffer(Node *Start) {
  if (Start == nullptr || Start->GetNext() == nullptr) {
    return;
  }

  Node *Prev = Start;
  Node *Curr = Prev->GetNext();

  while (Curr != nullptr) {

    Node *Check = Start;

    while (Check != Curr) { // Check for earlier duplicates

      if (Check->GetValue() == Curr->GetValue()) {
        Prev->SetNext(Curr->GetNext());
        Curr = Curr->GetNext();
        break; // All other duplicates have been removed
      }
      Check = Check->GetNext();
    }
    if (Check == Curr) { // Update the current
      Prev = Curr;
      Curr = Curr->GetNext();
    }
  }
}
```

#### Testing The Solutions OR Driver For Solution

Write your code in the `main.cpp` file, the tests are located at the bottom of the file.

<!-- Don't remove -->
Go to [Top](#top)
