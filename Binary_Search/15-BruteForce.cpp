#include <iostream>
#include <vector>
using namespace std;

int floorSqrt(int n)
{
    int ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n * 1ll)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
