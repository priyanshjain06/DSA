// NOTE Given an integer n, find and print the prime factors of the number n.

// ANCHOR Thus, the prime factorization of 36 is  2*2*3*3.

#include <iostream>
#include <cmath>
#include <set>
using namespace std;
// Function to find and print the unique prime factors
void findUniquePrimeFactors(int n)
{
    set<int> primeFactors; // REVIEW  // Use a set to store unique prime factors

    // Handle divisibility by 2 first (the only even prime)
    while (n % 2 == 0)
    {
        primeFactors.insert(2);
        n = n / 2;
    }

    // Handle divisibility by odd numbers from 3 to sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
       
            n = n / i;
        }
    }

    // If n is still greater than 1, then it's prime
    if (n > 1)
    {
        primeFactors.insert(n);
    }
    
    // Print the unique prime factors
    cout << "Unique prime factors: ";
    for (int factor : primeFactors)
    {
        cout << factor << " ";
    }
    cout << endl;
}

int main()
{
    int n = 1483; // Example number
    findUniquePrimeFactors(n);
    return 0;
}
