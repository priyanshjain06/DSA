// REVIEW -  Time Complexity : O(nloglogn)
#include <iostream>
#include <vector>
using namespace std;

// Optimized Sieve of Eratosthenes function to find all prime numbers up to N

void sieveOfEratosthenes(int N)
{
    if (N < 2)
    {
        cout << "No primes less than 2." << endl;
        return;
    }

    // Create a boolean array "isPrime" and initialize all entries as true
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    // Only go up to the square roowt of N
    for (int i = 2; i * i <= N; i++) // REVIEW -
    {
        if (isPrime[i])
        { // If i is prime
            // Start marking multiples of i from i^2, as smaller multiples will already be marked
            for (int j = i * i; j <= N; j += i) // REVIEW - j+=i
            {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers up to " << N << ": ";
    for (int i = 2; i <= N; i++) // REVIEW from 2
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int N = 50; // Example input
    sieveOfEratosthenes(N);
    return 0;
}
