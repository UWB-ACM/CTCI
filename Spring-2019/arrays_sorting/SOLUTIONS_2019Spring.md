# Arrays and Sorting

Problems and solutions for Arrays & Sorting session on April 12, 2019.

## Problems

### 1. Array Products

Source: http://www.crazyforcode.com/array/

**Scenario:** 

Given an array of `n` integers where `n > 1`, return an array where each index contains the integer product of all items in the original array except the integer at the given index.

**Function Signature:**

C++:

```c++
#include <vector>
using namespace std;

vector<int> arrayProduct(vector<int> start);
```

Java:

```java
public int[] arrayProduct(int[] start) {}
```

### 2. PROBLEM TODO :bug:

Source: TODO :bug:

**Scenario:** 

Problem Statement TODO :bug:

**Example Input:**

If the problem is simple enough, remove this section. TODO :bug:

**Function Signature:**

TODO :bug:

### 3. Unique Paths II

Source: TODO :bug:

**Scenario:** 

Problem Statement TODO :bug:

**Example Input:**

If the problem is simple enough, remove this section. TODO :bug:

**Function Signature:**

TODO :bug:

## Solutions

### 1. Array Products

Source: http://www.crazyforcode.com/array/

**Naive/Simple Solution:** 

Pseudocode:
```
for item in original:
    product = 1
    for all other items in original:
        product *= other item value
    append product to new array
```

The complexity of this solution is `N^2`.

**Optimal solution:**

The optimal solution for this problem only calculates the array's product once, and divides the total product by the value in the original array to find the correct value for the resulting array.

_Note: this implementation requires special handling of an edge case: one or more zeroes in the original array._

```java
// Solution Method Definition
// Note: this is the optimized solution
public int[] arrayProduct(int[] start) {
    int total = 1;
    int nonZeroTotal = 1;
    int zeroCount = 0;
    // get total product of array
    for (int i = 0; i < start.length; i++) {
        if (start[i] == 0) {
            zeroCount++;
            total = 0;
        } else {
            total *= start[i];
            nonZeroTotal *= start[i];
        }
    }
    // create new array to store result
    int[] result = new int[start.length];
    for (int i = 0; i < start.length; i++) {
        if (start[i] == 0) {
            if (zeroCount == 1) {
                result[i] = nonZeroTotal;
            } else {
                result[i] = 0;
            }
        } else {
            result[i] = total / start[i];
        }
    }
    return result;
}
```

**Testing The Solutions:**

The executable Java solution for this problem is located under `Spring-2019/arrays_sorting/product_of_array/GetProduct.java`.

The output for the Java solution is:

```
$ javac GetProduct.java
$ java GetProduct
Original is:	1 2 3 4 5 6 
Result is:	720 360 240 180 144 120 
Original is:	2 5 9 1 0 6 -3 12 -1 
Result is:	0 0 0 0 19440 0 0 0 0 
$
```

### 2. Coins

Source: TODO :bug:

**Naive/Simple Solution:** 

TODO :bug:

**Optimal solution:**

TODO :bug:

**Testing The Solutions:** OR **Driver For Solution**  

TODO :bug:

## 3. Unique Paths II

Source: TODO :bug:

**Naive/Simple Solution:** 

TODO :bug:

**Optimal solution:**

TODO :bug:

**Testing The Solutions:** OR **Driver For Solution**  

TODO :bug:


