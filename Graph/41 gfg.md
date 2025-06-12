# Floyd-Warshall Algorithm Problem

## Problem Statement

You are given a **weighted directed** graph, represented by an adjacency matrix, **dist[][]** of size **n × n**, where **dist[i][j]** represents the weight of the edge from **node i to node j**. If there is no direct edge, **dist[i][j]** is set to a large value (i.e., **10⁸**) to represent infinity. The graph may contain **negative edge weights**, but it does not contain any **negative weight cycles**.

Your task is to find the **shortest distance** between every pair of nodes **i** and **j** in the graph.

**Note:** Modify the distances for every pair **in place**.

## Examples

### Example 1

**Input:**
```
dist[][] = [
  [0, 4, 108, 5, 108], 
  [108, 0, 1, 108, 6], 
  [2, 108, 0, 3, 108], 
  [108, 108, 1, 0, 2], 
  [1, 108, 108, 4, 0]
]
```

**Output:**
```
[
  [0, 4, 5, 5, 7], 
  [3, 0, 1, 4, 6], 
  [2, 6, 0, 3, 5], 
  [3, 7, 1, 0, 2], 
  [1, 5, 5, 4, 0]
]
```

**Explanation:**
```
Each cell dist[i][j] in the output shows the shortest distance from node i to node j, 
computed by considering all possible intermediate nodes.
```

### Example 2

**Input:**
```
dist[][] = [
  [0, -1, 2], 
  [1, 0, 108], 
  [3, 1, 0]
]
```

**Output:**
```
[
  [0, -1, 2], 
  [1, 0, 3], 
  [2, 1, 0]
]
```

**Explanation:**
```
Each cell dist[i][j] in the output shows the shortest distance from node i to node j, 
computed by considering all possible intermediate nodes.

• From 2 to 0: shortest distance = 2
  Path: 2 → 1 → 0
  
• From 1 to 2: shortest distance = 3
  Path: 1 → 0 → 2
```