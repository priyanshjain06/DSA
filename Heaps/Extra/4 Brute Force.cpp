#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int cooldownTime)
    {
        unordered_map<char, int> freq; // Stores task counts
        for (char task : tasks)
        {
            freq[task]++;
        }

        priority_queue<int> pq; // Max heap for highest frequency tasks
        for (auto f : freq)
        {
            pq.push(f.second);
        }

        queue<pair<int, int>> cooldownQueue; // (remaining tasks(frequency), ready time)
        int time = 0;                        // Tracks total time taken

        while (!pq.empty() || !cooldownQueue.empty())
        {
            time++;

            // Pick the most frequent task from the heap
            if (!pq.empty())
            {
                int remaining = pq.top() - 1;
                pq.pop();
                if (remaining > 0)
                {
                    cooldownQueue.push({remaining, time + cooldownTime}); // Push to cooldown
                }
            }

            // Move tasks from cooldown back to heap when they are ready
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time)
            {
                pq.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};

int main()
{
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int cooldownTime = 2;
    cout << "Minimum time needed: " << sol.leastInterval(tasks, cooldownTime) << endl;
    return 0;
}
