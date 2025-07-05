#include <iostream>
using namespace std;

int removeRightmostSetBit(int x)
{
    return x & (x - 1);
}

