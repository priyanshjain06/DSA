#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
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

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // If we couldn't process all nodes, there's a cycle (invalid order)
        if (topo.size() != V) // REVIEW -
            return {};

        return topo;
    }

public:
    string findOrder(vector<string> &words)
    {
        unordered_set<char> uniqueChars; // REVIEW -
        for (const string &word : words) // FIXME
        {
            for (char ch : word)
            {
                uniqueChars.insert(ch);
            }
        }
        int K = uniqueChars.size(); // REVIEW Correctly determine the number of unique letters

        vector<int> adj[26]; // REVIEW -  26 size

        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) // REVIEW - till length
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // FIXME
                    found = true;                            // REVIEW -
                    break;                                   // REVIEW -
                }
            }

            // If no mismatch found and s1 is longer than s2, ordering is invalid
            
            if (!found && s1.size() > s2.size())
            {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj);
        if (topo.empty())
            return ""; // If cycle detected, return ""

        string ans = "";

        for (int node : topo)
        {
            char ch = 'a' + node; // Convert index to character

            if (uniqueChars.count(ch))
            // FIXME count means it checks whether the ch is present in the input (uniqueChars) or not Check if it's in the given words

            {
                ans += ch;
            }
        }

        return ans;
    }
};
