#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);

        // Construct adjacency list and in-degree array
        for (auto &pre : prerequisites) //REVIEW
        {
            adj[pre.second].push_back(pre.first);//REVIEW - second task should be completed before first so second -> first
            indegree[pre.first]++;
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count == N; // If all tasks are processed, no cycle exists
    }
};
