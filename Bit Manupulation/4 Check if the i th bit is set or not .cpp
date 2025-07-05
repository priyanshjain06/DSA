// REVIEW -  using left shift :
//  ANCHOR - Time Complexity - O(1)

#include <iostream>
using namespace std;
bool isIthBitSet(int n, int i)
{
    // Perform bitwise AND between n and mask
    return (n & (1 << i)) != 0;
}


// NOTE using right shift :

// #include <iostream>
// using namespace std;

// bool isIthBitSetRightShift(int n, int i) {
//     // Right shift n by i positions and check the least significant bit
//     return (n >> i) & 1;
// }
