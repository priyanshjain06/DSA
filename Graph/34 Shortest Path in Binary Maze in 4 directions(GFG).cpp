// User function Template for C++
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // REVIEW n and m is the size of the row and column of matrix A and x and y are the coordinates of the destination

        //  If the starting point is blocked
        if (A[0][0] == 0) // REVIEW
            return -1;

        // Directions for up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // BFS queue storing {x, y, steps}
        queue<vector<int>> q;//REVIEW queue is used 
        q.push({0, 0, 0}); // {row, col, distance}

        // Visited matrix
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[0][0] = true;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
            int steps = curr[2];

            if (row == X && col == Y)
                return steps;

            // Explore 4 directions
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                    A[newRow][newCol] == 1 && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol, steps + 1});
                }
            }
        }

        return -1; // If destination not reachable
    }
};
