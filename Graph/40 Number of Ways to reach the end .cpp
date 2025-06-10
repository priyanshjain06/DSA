#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // Each node stores a list of pairs: (neighbor, edge weight)
        vector<pair<int, int>> adj[n];

        // Build the adjacency list
        for (auto &it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Use long long for large values
        using ll = long long; // REVIEW

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        // REVIEW
        // FIXME how ll is used

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7; // REVIEW

        dist[0] = 0;
        ways[0] = 1; // REVIEW
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();

            for (auto &[adjNode, weight] : adj[node])
            {
                ll newDist = dis + weight;
                if (newDist < dist[adjNode])
                {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                }
                else if (newDist == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
