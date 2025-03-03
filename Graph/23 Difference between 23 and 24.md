# Difference Between "Checking Feasibility" and "Finding a Task Order".

## How the Code is Different?

| Feature          | **Checking Feasibility (1st Question)** | **Finding a Task Order (2nd Question)** |
|-----------------|----------------------------------------|----------------------------------------|
| **Return Type**  | `bool` (`true` if possible, `false` if cycle exists) | `vector<int>` (empty if cycle exists) |
| **Output**       | `"Yes"` / `"No"` | A valid order of tasks |
| **Cycle Handling** | If cycle exists, return `false` | If cycle exists, return `[]` (empty list) |
| **Final Step**   | Just checks if `count == n` | Returns `topo` list |