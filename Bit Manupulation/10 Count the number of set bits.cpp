// NOTE  This  is the most optimal solution
// REVIEW time complexity : O(no of bits)
#include <iostream>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while (n > 0) //REVIEW - 
    {
        n = n & (n - 1); // Removes the rightmost set bit
        count++;
    }
    return count;
}

int main()
{
    int num = 29; // Example number
    cout << "The number of set bits in " << num << " is: " << countSetBits(num) << endl;
    return 0;
}
