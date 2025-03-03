#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to calculate GCD using Euclid's Algorithm
    long long gcd(long long a, long long b)
    {
        while (b != 0)
        {
            a = a % b;  // Equivalent to a = a % b
            swap(a, b); // Swap a and b
        }
        return a;
    }

    // Function to calculate LCM using the formula
    long long lcm(long long a, long long b)
    {
        return (a * b) / gcd(a, b); 
    }

    // Function to calculate both LCM and GCD
    vector<long long> lcmAndGcd(long long a, long long b)
    {
        long long g = gcd(a, b); // Find GCD
        long long l = lcm(a, b); // Find LCM using the formula

        // Return both LCM and GCD in a vector
        return {l, g};
    }
};
