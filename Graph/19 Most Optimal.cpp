class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> revGraph(n); //  Reversed graph
        vector<int> outDegree(n, 0);     // Out-degree count

        // Step 1: Build reverse graph & count out-degrees
        for (int u = 0; u < n; ++u) // REVIEW
        {
            for (int v : graph[u]) // REVIEW
            {
                revGraph[v].push_back(u); // REVIEW  reverse the edge
            }
            outDegree[u] = graph[u].size(); // REVIEW
        }

        // Step 2: Queue for nodes with out-degree 0 (terminal nodes)
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (outDegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false); // Track safe nodes

        // Step 3: BFS (Kahn's algorithm)
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int prev : revGraph[node])
            {
                outDegree[prev]--;
                if (outDegree[prev] == 0)
                    q.push(prev);
            }
        }

        // Step 4: Collect all safe nodes
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (safe[i])
                result.push_back(i);
        }

        return result;
    }
};
