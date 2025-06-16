# Stock Trading Problems Comparison

## LeetCode 121 vs LeetCode 122

| **Feature** | **LeetCode 121** | **LeetCode 122** |
|-------------|------------------|------------------|
| **Buy/Sell Count** | Only once | Multiple times allowed |
| **Strategy** | Find min price, max profit | Greedy: Sell every local peak |
| **Return** | Max single profit | Max total profit from many trades |
| **Real-world Analogy** | One long-term investment | Day trading |

---

## Key Differences

### LeetCode 121: Best Time to Buy and Sell Stock
- **🎯 Objective:** Single transaction optimization
- **📊 Approach:** Track minimum price seen so far and maximum profit
- **💡 Strategy:** Buy at lowest point, sell at highest point after buying
- **🔒 Constraint:** Can only buy once and sell once

### LeetCode 122: Best Time to Buy and Sell Stock II
- **🎯 Objective:** Multiple transaction optimization
- **📊 Approach:** Capture every profitable opportunity
- **💡 Strategy:** Buy before every price increase, sell before every price decrease
- **🔄 Flexibility:** Unlimited transactions allowed

---

## Solution Patterns

### Problem 121 Pattern
```
Track: min_price, max_profit
For each price:
  - Update min_price if current < min_price
  - Update max_profit if (current - min_price) > max_profit
```

### Problem 122 Pattern
```
Track: total_profit
For each consecutive pair:
  - If price[i+1] > price[i]: add difference to profit
  - This captures all upward movements
```

