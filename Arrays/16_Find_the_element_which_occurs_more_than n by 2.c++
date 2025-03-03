// LINK -  the approach is called MOORE VOTING ALGO

// LINK -  here we use 2 steps 1: counter 2: checking the element in array again using a loop

// LINK - Initialize 2 variables:
//  Count –  for tracking the count of element
//  Element – for which element we are counting
//  Traverse through the given array.
//  If Count is 0 then store the current element of the array as Element.
//  If the current element and Element are the same increase the Count by 1.
//  If they are different decrease the Count by 1.
//  The integer present in Element should be the result we are expecting

// NOTE time complexity : O(n) + O(n) (optinal) and space complexity : O(1)
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el;      // Element

    // applying the algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i])
            cnt++;
        else
            cnt--;
    }
    
    // checking if the stored element
    //  is the majority element:
    int cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
