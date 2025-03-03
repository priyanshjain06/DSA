#include <iostream>
using namespace std;

int countBitFlips(int A, int B)
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

int main()
{
    int A = 29, B = 15; // Example numbers (29 = 11101, 15 = 01111)
    cout << "Number of bit flips required to convert " << A << " to " << B << " is: " << countBitFlips(A, B) << endl;
    return 0;
}
