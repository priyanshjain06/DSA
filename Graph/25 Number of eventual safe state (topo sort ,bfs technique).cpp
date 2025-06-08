#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adjRev[V];
        int indegree[V] = {0};

        // Reverse the graph and calculate indegrees
        for (int i = 0; i < V; i++) // REVIEW -
        {
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i); // REVIEW - 
                indegree[i]++;           // REVIEW -
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Push all nodes with indegree 0 to the queue
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Perform BFS
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end()); // REVIEW -
        return safeNodes;
    }
};