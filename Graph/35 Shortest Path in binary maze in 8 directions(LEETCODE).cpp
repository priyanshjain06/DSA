#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // If starting or ending cell is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) // REVIEW
            return -1;

        // 8 directions
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // BFS Queue: {row, col, steps}
        queue<tuple<int, int, int>> q; // REVIEW
        q.push({0, 0, 1});             // REVIEW  steps = 1 since we count starting cell

        // Visited matrix
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty())
        {
            auto [row, col, steps] = q.front(); // REVIEW accessing the tuple queue
            q.pop();

            // Reached destination
            if (row == n - 1 && col == n - 1) // REVIEW
                return steps;

            for (auto [dx, dy] : directions)
            {
                int newRow = row + dx;
                int newCol = col + dy;

                // Boundary & condition check
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && !visited[newRow][newCol])
                // REVIEW
                {

                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol, steps + 1}); // REVIEW
                }
            }
        }
        return -1; // No path found
    }
};