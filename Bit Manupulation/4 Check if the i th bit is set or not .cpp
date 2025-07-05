// REVIEW -  using left shift :
//  ANCHOR - Time Complexity - O(1)

#include <iostream>
using namespace std;
bool isIthBitSet(int n, int i)
{
    // Perform bitwise AND between n and mask
    return (n & (1 << i)) != 0;
}
int main()
{
    int n = 5; // Binary: 101
    int i = 2;

    if (isIthBitSet(n, i))
    {
        cout << "The " << i << "-th bit is set." << endl;
    }
    else
    {
        cout << "The " << i << "-th bit is not set." << endl;
    }

    return 0;
}

// NOTE using right shift :

// #include <iostream>
// using namespace std;

// bool isIthBitSetRightShift(int n, int i) {
//     // Right shift n by i positions and check the least significant bit
//     return (n >> i) & 1;
// }

// int main() {
//     int n = 5; // Binary: 101
//     int i = 2;

//     if (isIthBitSetRightShift(n, i)) {
//         cout << "The " << i << "-th bit is set." << endl;
//     } else {
//         cout << "The " << i << "-th bit is not set." << endl;
//     }
//     return 0;
// }