// NOTE

// REVIEW -  Time Complexity : O(n) and Space Complexity : O(1)

// ANCHOR -  for brute force see screenshot (concept of hashmap)

// NOTE -  we will use the concept of baskets here

#include <iostream>
#include <vector>
using namespace std;
int findSingleElement(const vector<int> &arr)
{
    int one = 0, two = 0;

    for (int i : arr)
    {
        // Update one and two as explained
        one = (one ^ i) & ~two;
        two = (two ^ i) & ~one;
    }
    return one; // 'one' now contains the element that appears only once
}
int main()
{
    vector<int> arr = {6, 6, 6, 3, 3, 3, 7}; // Example input
    cout << "The element that appears only once is: " << findSingleElement(arr) << endl;
    return 0;
}
