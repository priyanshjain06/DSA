#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt}); // REVIEW
            adj[v].push_back({u, wt}); // REVIEW
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // REVIEW
        vector<int> dist(n + 1, 1e9);                                                       // REVIEW -  1e9 is INT_MAX , n+1

        vector<int> parent(n + 1); // REVIEW n+1
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1}); // {distance, node}

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    parent[adjNode] = node; // REVIEW
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = n; // REVIEW last node is checked first !
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // REVIEW 1 is always the soruces (start)
        reverse(path.begin(), path.end());

        path.insert(path.begin(), dist[n]); // FIXME  add total cost

        return path;
    }
};