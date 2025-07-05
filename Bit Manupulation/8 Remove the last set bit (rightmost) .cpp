#include <iostream>
using namespace std;

int removeRightmostSetBit(int n)
{
    return n & (n - 1);
}
