# Next Smaller Element Algorithm 🧠  
**Find the first element to the right that is smaller than the current element.**  

### **Input Array**  
`arr = [4, 8, 5, 2, 25]`  

---

## **Step-by-Step Execution**  

| **Index** | **Element** | **Stack Before** | **Stack After** | **Next Smaller Element** |
|-----------|------------|------------------|-----------------|---------------------------|
| **4**     | 25         | `[-1]`           | `[-1, 25]`      | `-1` (No element after)    |
| **3**     | 2          | `[-1, 25]`       | `[-1, 2]`       | `-1` (25 > 2, popped)      |
| **2**     | 5          | `[-1, 2]`        | `[-1, 2, 5]`    | `2` (2 < 5)                |
| **1**     | 8          | `[-1, 2, 5]`     | `[-1, 2, 5, 8]` | `5` (5 < 8)                |
| **0**     | 4          | `[-1, 2, 5, 8]`  | `[-1, 2, 4]`    | `2` (2 < 4, 5 & 8 popped)  |

---

### **Final Output**  
✅ `[2, 5, 2, -1, -1]`  

---

### **Key Observations** 🔎  
1. **Right-to-Left Processing** → The algorithm scans the array from the end.  
2. **Monotonic Stack** → Maintains elements in increasing order (top is smallest).  
3. **Popping Rule** → If current element is ≤ stack top