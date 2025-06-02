// NOTE :  we can only insert two different fruits consecutively into the  basket

// REVIEW -  It can be converted into a problem something just like this :
//  Maximum  length subarray  with at most 2 types of  different numbers.

// ANCHOR  Time Complexity : O(n^2) and Space Complexity : O(3)

// REVIEW -  We will use set to implement

#include <set>
#include <iostream>
using namespace std;

// REVIEW -  k here is the number of the different type of fruits here !

int Max(int k, int n, int nums[])
{
    int maxlen = 0;
    for (int i = 0; i <= n-1; i++)
    {
        set<int> set; //REVIEW 
        for (int j = i; j < n; j++)
        {
            set.insert(nums[j]);

            if (set.size() <= 2) //REVIEW
            {
                maxlen = max(maxlen, j - i + 1);
            }
            
            else
            {
                break;
            }
        }
    }
}