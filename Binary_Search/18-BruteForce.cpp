#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) //REVIEW - day is my current array value
{
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            cnt++;
        else
        {
            noOfB += (cnt / k);
            cnt = 0; //REVIEW - 
        }
    }
    noOfB += (cnt / k); //REVIEW - 
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();
    if (val > n)
        return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) // range of possible answer
    {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}
