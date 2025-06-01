# Water Trapping Algorithm Logic

## Problem Logic Recap:

At each index, **water trapped = min(maxLeft, maxRight) - height[i]**

But instead of calculating `maxLeft[]` and `maxRight[]` arrays (which take O(n) space), we're using **two pointers** and **two variables**: `maxLeft`, `maxRight` to simulate it.

## Algorithm Logic Table

| Condition                       | Why we check it                   | What we do       |
| ------------------------------- | --------------------------------- | ---------------- |
| `height[left] <= height[right]` | Left is smaller → safe to process | Check `maxLeft`  |
| `height[left] >= maxLeft`       | New boundary                      | Update `maxLeft` |
| Else                            | Lower than left boundary          | Trap water       |
| Same for right side             | Right is smaller                  | Use `maxRight`   |
