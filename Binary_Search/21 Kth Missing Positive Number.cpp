// NOTE Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

// REVIEW - Time Complexity: O(logN) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    // NOTE see its burte force !
    int low = 0, high = n - 1; //REVIEW high is n-1 
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1); // REVIEW
        if (missing < k)                    // REVIEW -
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1; //REVIEW  or  low+k
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
