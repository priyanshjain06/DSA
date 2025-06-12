// User function Template for C++
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Step 1: Initialize distances
        vector<int> dist(V, 1e8); // Or use INT_MAX if preferred
        dist[src] = 0;

        // Step 2: Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0]; // or use it.first
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }

        // Step 3: Check for negative-weight cycles
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                // Negative cycle detected
                return {-1};
            }
        }

        return dist;
    }
};
