// NOTE - Find the Majority Element that occurs more than N/2 times where n is size of array

// LINK -  the approach is to use linear search using two loop and creating a counter

// NOTE time complexity : O(n^2)

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
