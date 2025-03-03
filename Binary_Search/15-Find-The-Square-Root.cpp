// REVIEW  Alternate Question : Find the max integer whose square is <=n
#include <iostream>
#include <vector>
using namespace std;
int floorSqrt(int n)
{
    int low = 1, high = n; //REVIEW - 
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    return high; //REVIEW 
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
