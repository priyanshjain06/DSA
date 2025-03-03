// REVIEW Time Complexity : O(1) and Space Complexity : O(1)
// NOTE see screenshot too 

#include <iostream>
using namespace std;

// Function to compute XOR from 1 to n
int xorTillN(int n)
{
    // XOR pattern based on n % 4
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0; // n % 4 == 3
}
// Function to compute XOR from l to r
int findXorInRange(int l, int r)
{
    return xorTillN(r) ^ xorTillN(l - 1); //REVIEW 
}
int main()
{
    int l, r;
    cout << "Enter the range (l and r): ";
    cin >> l >> r;

    int result = findXorInRange(l, r);
    cout << "XOR from " << l << " to " << r << " is: " << result << endl;
    return 0;
}

//n       XOR from 1 to n
// -------------------------
// 1       1              (1)
// 2       1 ^ 2          = 3
// 3       1 ^ 2 ^ 3      = 0
// 4       1 ^ 2 ^ 3 ^ 4  = 4
// 5       1 ^ 2 ^ 3 ^ 4 ^ 5 = 1
// 6       1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7
// 7       1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0
// 8       1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
