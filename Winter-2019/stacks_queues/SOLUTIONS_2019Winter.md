# Stacks and Queues

Problems and solutions for Stacks & Queues session on February 8, 2019.

## Problems

### 1. Balanced Brackets

Source: [HackerRank](https://www.hackerrank.com/challenges/balanced-brackets/problem)

#### Scenario

Given a string containing brackets, determine if it is balanced.

Brackets are defined as `()`, `[]`, or `{}`. Brackets are considered balanced if there is a matching left bracket for every right bracket (and vice versa), and if bracket sets are nested properly.

#### Example Input

Example 1:
```
  Input: “({[]})”
  Output: true
```

Example 2:
```
  Input: “{{}”
  Output: false
```

#### Function Signature

C++:

```c++
bool isBalanced(string sample) {}
```

Python:

```python
def is_balanced(string):
    # your code here
```

### 2. Queue with Two Stacks

Source: [HackerRank](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem)

#### Scenario

Implement a `MyQueue` class which implements a queue using two stacks.

#### Class Definition

At a minimum, the class should provide functions to initialize the queue and push or pop items from the queue.

C++ header for one possible implementation:

```c++
template<class T>
class TwoStackQueue {
    public:
        TwoStackQueue();
        ~TwoStackQueue();
        void Push(T item);
        bool Pop();
        int size();
    private:
        stack<T>* front;
        stack<T>* back;
        void rebalance();
};
```

## Solutions

### 1. Balanced Brackets

Source: [HackerRank](https://www.hackerrank.com/challenges/balanced-brackets/problem)

#### Optimal Solution

The fundamental algorithm is as follows:

```
Create a stack structure
Iterate through input string. For each character:
    If the character is an opening brace, push it to the stack
    If the character is a closing brace:
        If the stack is empty, return FALSE
        Pop the last item added to the stack
        If the popped item is not the correct opening brace type, return FALSE
If the stack has items in it at the end, 1+ braces were not matched; return FALSE
Otherwise, return TRUE
```

The solution implementation in Python is as follows:

```python
def is_balanced(string):
    # the list we will use to represent the parens stack
    braces = []
    # iterate through string, looking for parens characters
    for letter in string:
        # if a new opening brace, push the brace onto the stack
        if letter in "[{(":
            braces.append(letter)
        # if a closing brace, make sure pair is correct
        elif letter in "]})":
            # edge case: closing brace with no opening brace
            if len(braces) == 0:
                return False
            last_char = braces.pop()
            if last_char == "[" and letter != "]":
                return False
            elif last_char == "{" and letter != "}":
                return False
            elif last_char == "(" and letter != ")":
                return False
    if len(braces) > 0:
        return False
    return True
```

#### Testing The Solutions  

Executable Python and C++ solutions for this problem are located under `Winter-2019/stacks_queues/balanced_parens`.

The output for the Python solution is:

```console
$ python parens.py
expected result: False  actual result: False    string: {{}
expected result: False  actual result: False    string: ){}[({a})]
expected result: True   actual result: True     string: ({}[]{(([][]))})
expected result: True   actual result: True     string: (((testing)))
expected result: True   actual result: True     string: if(this_is_dumb){quit};
expected result: False  actual result: False    string: (can{you(code}this)mess]
expected result: True   actual result: True     string: (((([[{}]]))))
$
```

### 2. Queue with Two Stacks

Source: [HackerRank](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem)

#### Optimal Solution

For this structure to work and element order to be preserved, new items will get pushed to the stack designated `back`. When the stack for `front` is empty, all items in `back` will get pushed to the `front` stack, so that the LIFO back items have their order reversed and the oldest items in `back` are the newest items in `front`.

The three core methods of the implementation in C++ are as follows:

```c++
// push item into the queue
void Push(T item) {
    back->push(item);
    if (front->size() == 0) {
        this->rebalance();
    }
}

// pop item from the queue
bool Pop() {
    if (front->size() != 0) {
        // useful to see the item that is being popped
        // return val also indicates whether operation was successful
        cout << "popping item: " << front->top() << endl;
        front->pop();
        if (front->size() == 0) {
            this->rebalance();
        }
        return true;
    }
    return false;
}

// function to move queue items when front->stack is empty
void rebalance() {
    while (back->size() > 0) {
        front->push(back->top());
        back->pop();
    }
}
```

#### Testing The Solutions

Executable Python and C++ solutions for this problem are located under `Winter-2019/stacks_queues/queue_from_stacks`.

The output of the C++ solution is as follows:

```console
$ g++ -o test queue_from_stacks.cpp
$ ./test
popping item: hello
popping item: world
popping item: on
popping item: fire
popping item: abc
popping item: xyz
$
```
