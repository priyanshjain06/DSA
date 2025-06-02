# Sliding Window Maximum - Deque Solution

## Problem Description

Given an array of integers `nums` and an integer `k`, return an array containing the maximum value in each sliding window of size `k`.

## Example

🔢 **Input:**
```
nums = [4, 0, -1, 3, 5, 3, 6, 8]
k = 3
```

🧾 **Legend:**
* **i**: Current index
* **nums[i]**: Current value
* **Deque (dq)**: Stores indices (we'll also show values for clarity)
* **Action**: What happened this step
* **Result**: Max value added to result (if any)

| i | nums[i] | Deque (Indices) | Deque (Values) | Action | Result |
|---|---------|-----------------|----------------|--------|--------|
| 0 | 4 | [0] | [4] | Push 0 (deque empty) | |
| 1 | 0 | [0, 1] | [4, 0] | Push 1 (0 < 4) | |
| 2 | -1 | [0, 1, 2] | [4, 0, -1] | Push 2 (-1 < 0) | **4** |
| 3 | 3 | [0, 1, 2] → [0, 1] → [0] → [3] | [4, 0, -1] → [4, 0] → [4] → [3] | Pop 2, 1 (3 > -1, 0), push 3 | **3** |
| 4 | 5 | [3] → [] → [4] | [3] → [] → [5] | Pop 3 (5 > 3), push 4 | **5** |
| 5 | 3 | [4, 5] | [5, 3] | Push 5 (3 < 5) | **5** |
| 6 | 6 | [4, 5] → [4] → [] → [6] | [5, 3] → [5] → [] → [6] | Pop 5, 4 (6 > 3, 5), push 6 | **6** |
| 7 | 8 | [6] → [] → [7] | [6] → [] → [8] | Pop 6 (8 > 6), push 7 | **8** |

✅ **Final Output:**
```
ans = [4, 3, 5, 5, 6, 8]
```

