# 🚀 The Stock Span Problem 📈

## 💼 Problem Definition

> The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span `arr[i]` of the stocks price on a given day `i` is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.

<div align="center">
  
  *How many consecutive days has the stock price been less than or equal to today's price?*
  
</div>

---

## 🧩 Examples

### Example 1

<table>
  <tr>
    <th colspan="7">Input Array</th>
  </tr>
  <tr>
    <td>100</td>
    <td>80</td>
    <td>60</td>
    <td>70</td>
    <td>60</td>
    <td>75</td>
    <td>85</td>
  </tr>
  <tr>
    <th colspan="7">Output Span</th>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>2</td>
    <td>1</td>
    <td>4</td>
    <td>6</td>
  </tr>
</table>

#### Explanation:

- **Day 1**: Price = 100, Span = 1 (100 is greater than or equal to itself)
- **Day 2**: Price = 80, Span = 1 (80 is less than 100)
- **Day 3**: Price = 60, Span = 1 (60 is less than 80)
- **Day 4**: Price = 70, Span = 2 (70 is greater than 60, but less than 80)
- **Day 5**: Price = 60, Span = 1 (60 is less than 70)
- **Day 6**: Price = 75, Span = 4 (75 is greater than 60, 60, 70, 60)
- **Day 7**: Price = 85, Span = 6 (85 is greater than 75, 60, 70, 60, 80, but less than 100)

### Example 2

<table>
  <tr>
    <th colspan="6">Input Array</th>
  </tr>
  <tr>
    <td>10</td>
    <td>4</td>
    <td>5</td>
    <td>90</td>
    <td>120</td>
    <td>80</td>
  </tr>
  <tr>
    <th colspan="6">Output Span</th>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>2</td>
    <td>4</td>
    <td>5</td>
    <td>1</td>
  </tr>
</table>

#### Explanation:

- **Day 1**: Price = 10, Span = 1 (10 is greater than or equal to itself)
- **Day 2**: Price = 4, Span = 1 (4 is less than 10)
- **Day 3**: Price = 5, Span = 2 (5 is greater than 4, but less than 10)
- **Day 4**: Price = 90, Span = 4 (90 is greater than 5, 4, 10)
- **Day 5**: Price = 120, Span = 5 (120 is greater than 90, 5, 4, 10)
- **Day 6**: Price = 80, Span = 1 (80 is less than 120)

---
