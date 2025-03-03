#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int cooldown)
    {
        unordered_map<char, int> freq; // Stores task counts
        int maxFreq = 0, maxFreqCount = 0;

        // Step 1: Count task frequency
        for (char task : tasks)
        {
            freq[task]++;
            if (freq[task] > maxFreq)
            {
                maxFreq = freq[task]; // Update max frequency
                maxFreqCount = 1;     // Reset count of max freq tasks
            }
            else if (freq[task] == maxFreq)
            {
                maxFreqCount++; // Count how many tasks have max frequency
            }
        }

        // Step 2: Use formula
        int gapCount = maxFreq - 1;
        int emptySlots = gapCount * (cooldown - (maxFreqCount - 1));
        int availableTasks = tasks.size() - (maxFreq * maxFreqCount);
        int idleTime = max(0, emptySlots - availableTasks);

        return tasks.size() + idleTime;
    }
};

int main()
{
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int cooldown = 2;
    cout << "Minimum time needed: " << sol.leastInterval(tasks, cooldown) << endl;
    return 0;
}
