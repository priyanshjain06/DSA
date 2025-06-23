// REVIEW - https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

// REVIEW it uses dijkastra algo !
// REVIEW  same problem but here we can traverse in all 4 directions !

class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        // min-heap {cost, {i, j}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Directions: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto [cost, pos] = pq.top();
            pq.pop();

            int x = pos.first, y = pos.second;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    int newCost = cost + grid[nx][ny];
                    if (newCost < dist[nx][ny])
                    {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
