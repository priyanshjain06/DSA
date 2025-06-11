#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    // string -> node  string -> neighbour , double-> 2.0(value / weight )

    double dfs(string start, string end, unordered_set<string> &visited)
    {
        if (graph.find(start) == graph.end())
            return -1.0;
        if (start == end)
            return 1.0;

        visited.insert(start); // REVIEW

        for (auto &[neighbor, weight] : graph[start])
        // REVIEW first loop then check visited or not
        {
            if (visited.count(neighbor) == 1)
                continue; // skip if node is visited !
            double result = dfs(neighbor, end, visited);
            if (result != -1.0)
            {
                return weight * result;
            }
        }

        return -1.0; // REVIEW
    }

    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val}); // REVIEW
        }

        // Step 2: Answer each query using DFS
        vector<double> result;
        for (auto &query : queries)
        {
            string start = query[0];
            string end = query[1];
            unordered_set<string> visited; // REVIEW set of visited nodes
            result.push_back(dfs(start, end, visited));
        }

        return result;
    }
};
