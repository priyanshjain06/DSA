// REVIEW -  Time Complexity : O(sqrt(n))
#include <iostream>
#include <math.h>
using namespace std;

bool checkPrime(int n)
{

    int cnt = 0;

    // Loop through numbers from 1
    // to the square root of n.
    for (int i = 1; i <= sqrt(n); i++) // REVIEW start from 1
    {

        // If n is divisible by i
        // without any remainder.
        if (n % i == 0)
        {

            // Increment the counter.
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
    {
        // Return true, indicating
        // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else
    {
        // Return false, indicating
        // that the number is not prime.
        return false;
    }
}

int main()
{
    int n = 1483;
    bool isPrime = checkPrime(n);
    if (isPrime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
