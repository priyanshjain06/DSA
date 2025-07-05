// REVIEW -  Time Complexity : O(sqrt(n))

#include <iostream>
#include <math.h>
using namespace std;

bool checkPrime(int n)
{
    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++) // REVIEW start from 1
    {

        // If n is divisible by i
        // without any remainder.
        if (n % i == 0)
        {

            cnt = cnt + 1;

            // If n is not a perfect square,
            // count its reciprocal factor.
            if (n / i != i) // REVIEW - 36/6=6
            {
                cnt = cnt + 1;
            }
        }
    }

    // If the number of
    // factors is exactly 2.
    if (cnt == 2)
        return true; // REVIEW means n is prime number

    else
        return false;
}