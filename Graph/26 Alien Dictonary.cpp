#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
    // works for multiple components
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];     // FIXME
            string s2 = dict[i + 1]; // FIXME
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) // REVIEW -  till length
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // REVIEW -
                    break;                                       // REVIEW -
                }
            }
        }

        vector<int> topo = topoSort(K, adj); // REVIEW - pass adj array here
        string ans = "";
        for (auto it : topo)
        {
            ans = ans + char(it + 'a'); // REVIEW convert to character
        }
        return ans;
    }
};