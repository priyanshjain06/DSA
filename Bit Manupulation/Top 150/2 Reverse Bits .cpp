#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//REVIEW do all this is in unsigned int
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; ++i) {
            result <<= 1;           // Shift result left to make space
            result |= (n & 1);      // Add last bit of n to result
            n >>= 1;                // Drop the last bit from n
        }
        
        return result;
    }
};
