#include <iostream>
#include <cmath>
using namespace std;

int getProperDivisorsSum(int n)
{
    if (n <= 1)
        return 0;

    int sum = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }

    return sum;
}

// Function to check if two numbers form a friendly pair
bool areFriendlyPair(int num1, int num2)
{
    if (num1 <= 0 || num2 <= 0)
        return false;

    // Calculate sum of proper divisors for both numbers
    int sum1 = getProperDivisorsSum(num1);
    int sum2 = getProperDivisorsSum(num2);

    // Calculate abundance ratios and compare
    // Using cross multiplication to avoid floating point precision issues
    // sum1/num1 == sum2/num2 is equivalent to sum1*num2 == sum2*num1

    return (sum1 * num2) == (sum2 * num1); // REVIEW cross multiply to avoid floating point
}

int main()
{
    int num1, num2;

    // Read input
    cin >> num1 >> num2; //REVIEW 

    // Check if they form a friendly pair
    if (areFriendlyPair(num1, num2))
    {
        cout << "Friendly Pair" << endl;
    }
    else
    {
        cout << "Not Friendly Pair" << endl;
    }

    return 0;
}

/*
Test with the example:
Input: 6 28

For 6: proper divisors are 1, 2, 3 -> sum = 6
Abundance ratio = 6/6 = 1

For 28: proper divisors are 1, 2, 4, 7, 14 -> sum = 28
Abundance ratio = 28/28 = 1

Since both ratios are equal (1), they form a Friendly Pair.
*/