#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Step 1: Build the adjacency list
        // REVIEW this is optinal step !
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Set to get the node with the minimum distance
        set<pair<int, int>> st; // (distance, node)

        // Step 3: Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});

        // Step 4: Process the set
        while (!st.empty())
        {
            auto it = *(st.begin()); // FIXME
            st.erase(it);
            // we can erase it after node and d is fetched

            int node = it.second;
            int d = it.first;

            for (auto &neighbor : adj[node])
            {
                int adjNode = neighbor.first;
                int wt = neighbor.second;

                if (d + wt < dist[adjNode])
                {
                    // Remove the old entry if it exists
                    if (dist[adjNode] != INT_MAX)
                    {
                        st.erase({dist[adjNode], adjNode}); // FIXME
                    }

                    dist[adjNode] = d + wt;
                    st.insert({dist[adjNode], adjNode}); // REVIEW
                }
            }
        }

        // Step 5: Convert unreachable distances to -1
        // REVIEW this is optinal step
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
