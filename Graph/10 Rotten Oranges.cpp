#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size(), cols = grid[0].size();
    int days = 0, total = 0, rottenCount = 0;
    queue<pair<int, int>> q; // REVIEW -

    // Count total oranges and push initial rotten oranges into queue
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] != 0)
                total++; // REVIEW total = fresh +rooten
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    // Directions for adjacent cells (right, left, down, up)
    vector<int> delRow = {0, 0, 1, -1}, delCol = {1, -1, 0, 0};

    // BFS to spread rot
    while (!q.empty())
    {
        int size = q.size();
        rottenCount += size; // REVIEW -
        while (size--) //REVIEW - 
        {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + delRow[i], nc = c + delCol[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2; // REVIEW - no visisted vector
                    q.push({nr, nc}); // REVIEW -
                }
            }
        }
        if (!q.empty())
            days++;
    }

    return (total == rottenCount) ? days : -1;
}
