// REVIEW A divisor of an integer N is a positive integer that divides N without leaving a remainder.

// REVIEW divisor and factors are not same they are different
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> findDivisors(int n)
{
    vector<int> divisors;
    int sqrtN = sqrt(n); // SECTION square root , !

    for (int i = 1; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);

            if (n / i != i) // 25 / 5 = 5
            {
                divisors.push_back(n / i); // 30/5 = 6, store 6
            }
        }
    }

    return divisors;
}
