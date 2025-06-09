#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // Min-heap: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // REVIEW pq declearation !

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto [diff, pos] = pq.top(); // REVIEW
            auto [row, col] = pos;       // REVIEW -
            pq.pop();

            //REVIEW  or use this
            //   int diff = it.first;
            //  int row = it.second.first;
            //  int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}}); // REVIEW -
                    }
                }
            }
        }

        return 0;
    }
};
