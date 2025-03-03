#include <iostream>
using namespace std;
bool palindrome(int n)
{
    int revNum = 0;
    int dup = n; // REVIEW
    while (n > 0)
    {
        int ld = n % 10;

        revNum = (revNum * 10) + ld;

        n = n / 10;
    }
    if (dup == revNum)
        return true;
    else
        return false;
}
