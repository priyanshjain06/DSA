// NOTE -  why bfs ? to traverse all the connected components

// NOTE why not dfs ? we want to traverse level wise here since matrix given

// NOTE  New starting point => count ++

// NOTE  how to deterimine the starting point ? => by bfs and maintaining visited array

// NOTE how to check the island ? => use 8 direction checking !

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    void bfsIsland(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q; // REVIEW pair
        q.push({row, col});
        visited[row][col] = true;

        // REVIEW  8 directions: N, S, E, W, NE, NW, SE, SW
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // REVIEW

        // REVIEW  WHy two loops ? to traverse the matrix input !
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < m; ++col)
            {
                if (grid[row][col] == '1' && !visited[row][col]) // REVIEW -
                {
                    count++; // REVIEW
                    bfsIsland(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};