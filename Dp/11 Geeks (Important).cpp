// REVIEW - https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

// REVIEW it uses dijkastra algo !
// REVIEW  same problem but here we can traverse in all 4 directions ! and input size is  n*n not n*m

class Solution
{
public:
    // Function to return the minimum cost to reach bottom-right cell from top-left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Distance matrix initialized with max int value
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        // Min-heap: {cost, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Directions: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // Early exit if bottom-right is reached
            if (x == n - 1 && y == n - 1)
                return cost;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                // Check boundaries
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
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

        // Return the minimum cost to reach (n-1, n-1)
        return dist[n - 1][n - 1];
    }
};
