// NOTE Find the Majority Element that occurs more than N/2 times

// LINK -  using a unordered or ordered map and storing the element with its count in given array and checking the conditions

// NOTE - Time complexity : O(nlogn) +O(n)
// OR
// O(n) to O(n^2)

// LINK - Reason :We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

//NOTE and space Complexity : O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    // declaring a map:
    map<int, int> mpp;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
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