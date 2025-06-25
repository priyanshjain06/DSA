// REVIEW Space optimisation :
// NOTE similar to q 15

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;

    for (int i = 0; i < n; i++) // SECTION calculating total sum
    {
        totSum += arr[i];
    }

    if (totSum % 2 == 1) // SECTION -  if odd then cant be divided so false
        return false;
    else
    {
        int k = totSum / 2; // SECTION find the k

        vector<bool> prev(k + 1, false); // SECTION -  call the space optimisation function of the previous question

        prev[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> cur(k + 1, false);
            cur[0] = true;

            for (int target = 1; target <= k; target++)
            {
                bool notTaken = prev[target];

                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = notTaken || taken;
            }

            prev = cur;
        }

        return prev[k];
    }
}
