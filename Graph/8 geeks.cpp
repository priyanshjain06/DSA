#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &shape, int baseRow, int baseCol) // REVIEW -  base row and base col
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        shape.push_back({0, 0}); // REVIEW Store relative position

        int delRow[] = {-1, 1, 0, 0}; // REVIEW -
        int delCol[] = {0, 0, -1, 1}; // REVIEW -

        while (!q.empty())
        {
            auto [r, c] = q.front(); // REVIEW -
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    // Store relative position
                    shape.push_back({nrow - baseRow, ncol - baseCol}); // REVIEW -
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // REVIEW -
        set<vector<pair<int, int>>> uniqueIslands;     // REVIEW -

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int, int>> shape; // REVIEW -
                    bfs(i, j, grid, vis, shape, i, j); //REVIEW - 
                    uniqueIslands.insert(shape); // REVIEW -
                }
            }
        }
        return uniqueIslands.size();
    }
};
