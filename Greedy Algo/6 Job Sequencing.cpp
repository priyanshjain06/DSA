#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is completed before or on deadline
};

class Solution
{
public:
    static bool compareProfit(Job a, Job b) // REVIEW a and b are of job type!
    {
        return a.profit > b.profit; // Sort jobs by profit in descending order
    }

    pair<int, int> JobScheduling(vector<Job> &arr)
    {
        int n = arr.size();

        // Sort jobs in descending order of profit
        sort(arr.begin(), arr.end(), compareProfit);

        // Find the maximum deadline
        int maxi = arr[0].dead; // FIXME -

        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        vector<int> slot(maxi + 1, -1); // REVIEW  // Slot vector to track scheduled jobs

        int countJobs = 0, jobProfit = 0;
        // NOTE we are using i loop for looping vector input and j for finding the entery for slot !
        //  Iterate over all jobs
        for (int i = 0; i < n; i++)
        {
            // Try to find a slot for the current job
            for (int j = arr[i].dead; j > 0; j--) //REVIEW - 
            { // NOTE  use disjoint set union here to reduce it for time complexity

                if (slot[j] == -1)
                {                               // If the slot is free
                    slot[j] = i;                // Assign job to slot
                    countJobs++;                // Increment job count
                    jobProfit += arr[i].profit; // Add profit for this job
                    break;                      // REVIEW
                }
            }
        }

        return make_pair(countJobs, jobProfit); //REVIEW  Return the result
    }
};

int main()
{
    vector<Job> arr = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    Solution ob;
    pair<int, int> ans = ob.JobScheduling(arr);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}