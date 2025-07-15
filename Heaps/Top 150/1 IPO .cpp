#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();

        // Step 1: Store projects as pairs of (capital_required, profit)
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i)
        {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        // Step 3: Use max-heap to store affordable projects by profit
        priority_queue<int> maxProfitHeap;
        int i = 0;

        while (k--)
        {
            // Push all affordable projects to max-heap
            while (i < n && projects[i].first <= w)
            {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }

            if (maxProfitHeap.empty())
                break; // No affordable project

            w += maxProfitHeap.top(); // Choose the most profitable
            maxProfitHeap.pop();
        }

        return w;
    }
};
