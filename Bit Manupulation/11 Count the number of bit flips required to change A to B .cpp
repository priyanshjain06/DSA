#include <iostream>
using namespace std;


int countBitFlips(int A, int B) // REVIEW -  a is start and b is goal
{
    int diff = A ^ B; // XOR of A and B gives the positions where bits are different

    int count = 0;
    while (diff > 0)
    {
        diff = diff & (diff - 1); // Removes the rightmost set bit
        count++;
    }
    return count;
}
