// REVIEW We can also use the Dijkastra Algo here :
// REVIEW bellow is the Floyd Warshall Algo
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Step 1: Initialize graph with edge weights
        for (auto &it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++) // REVIEW for diagonal
            dist[i][i] = 0;

        // Step 2: Floyd-Warshall for all-pairs shortest paths
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue; // REVIEW -
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Step 3: Count reachable cities for each city
        int minReachable = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (dist[city][neighbor] <= distanceThreshold)
                    count++;
            }

            // Prefer the city with the greater index if count ties
            if (count <= minReachable)
            {
                minReachable = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};
