#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Step 1: Build the adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Min heap for Dijkstra (dist, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 3: Distance vector initialized to INF
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        // Step 4: Dijkstra's Algorithm
        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &[nei, weight] : adj[node])
            {
                if (d + weight < dist[nei])
                {
                    dist[nei] = d + weight;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // Step 5: Replace unreachable distances with -1
        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
