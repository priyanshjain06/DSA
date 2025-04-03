# Queue Implementation using Array

## Problem Statement

Implement a Queue using an Array. The queue should support two operations:

1. `push(x)`: Add element x to the rear of the queue.
2. `pop()`: Remove the element from the front of the queue and return it. If the queue is empty, return -1.

The queries are of the following types:

- `1 x`: Push 'x' into the queue.
- `2`: Pop an element from the queue and print the popped element. If the queue is empty, print -1.

## Examples

### Example 1:

```
Input: Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation:
For query 1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue will be {3}
1 4 the queue will be {3 4}
2   popped element will be 3
```

### Example 2:

```
Input: Queries = 1 3 2 2 1 4
Output: 3 -1
Explanation:
For query 1 3 the queue will be {3}
2   popped element will be 3 the queue will be empty
2   there is no element in the queue and hence -1
1 4 the queue will be {4}
```

### Example 3:

```
Input: Queries = 1 3 2 2 1 3
Output: 3 -1
Explanation:
For query 1 3 the queue will be {3}
2   popped element will be 3 the queue will be empty
2   there is no element in the queue and hence -1
1 3 the queue will be {3}
```
