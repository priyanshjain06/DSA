// NOTE  This  is the most optimal solution
// REVIEW time complexity : O(no of bits)
//SECTION - Brian Kernighan’s Algo	
#include <iostream>
#include <math.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n > 0) // REVIEW -
    {
        n = n & (n - 1); // Removes the rightmost set bit
        count++;
    }
    return count;
}

// REVIEW brute force

// int count = 0;
// while(n) {
//     if(n & 1) count++;
//     n >>= 1;
// }

// REVIEW most optimal way :
// O(1)

// __builtin_popcount(n);       // For 32-bit
// __builtin_popcountll(n);     // For 64-bit
