// ANCHOR Time complexity : O(n) and Space complexity : O(1) 

#include <iostream>
using namespace std;
int Max(int k, int nums[],int n)
{
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int zeroCount = 0;
    
    while (right < n)
    {
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        if(zeroCount > k) //NOTE not while 
        {
            if (nums[left] == 0)
            {
                zeroCount--;
            }
                left++;
        }
        
        if (zeroCount <= k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
            right++; //NOTE
    }
    return maxLen;
}
