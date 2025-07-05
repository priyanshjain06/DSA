// REVIEW - time complexity : O(n) and space complexity : O(1)
// ANCHOR -  Brute force to create a hashmap

// LINK -  Alternate question : Find the number that appears odd number of times

#include <iostream>
#include <vector>
using namespace std;

int findSingleElement(vector<int> &nums)
{
    int single = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        single = single ^ nums[i]; // XOR operation
    }
    return single;
}

