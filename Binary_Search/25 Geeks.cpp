class Solution
{
public:
    // REVIEW -  create two function to find max and sum !
    int getMax(vector<int> arr, int n)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    int getSum(vector<int> arr, int n)
    {
        int total = 0;
        for (int i = 0; i < n; i++)
            total += arr[i];
        return total;
    }

    int numberOfPainters(vector<int> arr, int n, int maxLen)
    {
        int total = 0, numPainters = 1;

        for (int i = 0; i < n; i++)
        {
            total += arr[i];

            if (total > maxLen)
            {

                total = arr[i];
                numPainters++;
            }
        }

        return numPainters;
    }

    int minTime(vector<int> &arr, int k)
    {
        int n = arr.size();
        int lo = getMax(arr, n);
        int hi = getSum(arr, n);

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            int requiredPainters = numberOfPainters(arr, n, mid);

            if (requiredPainters <= k)
                hi = mid; // REVIEW -

            else
                lo = mid + 1;
        }

        // required
        return lo;
    }
};