// REVIEW We need to remove the  minimum edges (extra edges which are more than n-1) in the individual component !

// User function Template for C++
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int countComponents(int n) // REVIEW -
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);  // REVIEW
        int extraEdges = 0; // REVIEW

        for (auto &e : edge)
        {
            int u = e[0], v = e[1];
            if (ds.findUPar(u) == ds.findUPar(v))  //REVIEW - 
            {
                // It's a redundant edge
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
                components++;
        }

        int neededEdges = components - 1;
        return (extraEdges >= neededEdges) ? neededEdges : -1; //REVIEW 
    }
};
