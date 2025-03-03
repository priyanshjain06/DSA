// NOTE Count Reverse Pairs
// Problem Statement : Given an array of numbers,
//                     you need to return the count of reverse pairs.Reverse Pairs are those pairs where i < j and arr[i] > 2 * arr[j].

// LINK  Time Complexity :O(n^2) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &a, int n) 
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

int team(vector<int> &skill, int n) //REVIEW - 
{
    return countPairs(skill, n); 
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
