Input: adj = [[2,3,1], [0], [0,4], [0], [2]]

Output: [0, 2, 4, 3, 1]

Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0
Visit 2 (the first neighbor of 0) → Output: 0, 2
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0
Visit 1 (the first neighbor of 0) → Output: 0, 1
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
