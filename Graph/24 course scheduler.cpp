#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        // Build adjacency list and compute indegree
        for (auto &pre : prerequisites) // REVIEW -
        {
            adj[pre[1]].push_back(pre[0]); // pre[1] -> pre[0]
            indegree[pre[0]]++;
        }

        queue<int> q;
        vector<int> order;

        // Push nodes with 0 indegree
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node); //REVIEW 

            for (auto next : adj[node])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        // If all tasks are included, return order; otherwise, return empty array
        return order.size() == n ? order : vector<int>{}; // REVIEW -
    }
};