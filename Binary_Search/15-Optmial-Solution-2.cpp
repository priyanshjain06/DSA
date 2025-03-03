#include <iostream>
#include <cmath> //REVIEW - 
using namespace std;

int floorSqrt(int n)
{
    int ans = sqrt(n);
    return ans;
}
int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans;
    return 0;
}
