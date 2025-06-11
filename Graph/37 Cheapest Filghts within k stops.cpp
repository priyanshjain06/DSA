#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Build adjacency list: node -> [(neighbor, weight)]
        vector<pair<int, int>> adj[n];
        
        for (auto &flight : flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // REVIEW  Queue holds: {stops, {node, total cost}}

        queue<pair<int, pair<int, int>>> q; // REVIEW queue is used !
        q.push({0, {src, 0}});

        // Distance array to track min cost to reach each node
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Ignore paths with more than k stops
            if (stops > k)
                continue; // REVIEW

            for (auto &[adjNode, weight] : adj[node])
            // REVIEW we can use  auto it also
            {
                int newCost = cost + weight;

                if (newCost < dist[adjNode])
                {
                    dist[adjNode] = newCost;
                    q.push({stops + 1, {adjNode, newCost}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst]; // REVIEW
    }
};
