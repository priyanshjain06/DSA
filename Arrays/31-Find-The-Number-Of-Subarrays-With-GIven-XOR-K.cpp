// NOTE Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// ANCHOR -  O(N) or O(N*logN) and Space Complexity is  O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size(); // size of the given array.
    int xr = 0;
    map<int, int> mpp; // declaring the map.
    mpp[xr]++;       //REVIEW -    // setting the value of 0,1 
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        // By formula: x = xr^k:
        int x = xr ^ k;

        // check if x appears in the map
        // if true increase count
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        // basically update the map
        mpp[xr]++;
    }
    return cnt; // REVIEW -
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
