#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[V];

        // Step 1: Convert edge list to adjacency list
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological sort
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 3: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        // Step 4: Relax edges in topological order
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Replace unreachable nodes with -1
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

// 🔰 Sample main function
int main()
{
    Solution sol;

    int V = 6, E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};

    vector<int> result = sol.shortestPath(V, E, edges);

    cout << "Shortest distances from source 0:\n";
    for (int dist : result)
    {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
