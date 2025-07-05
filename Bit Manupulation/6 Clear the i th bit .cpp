#include <iostream>
using namespace std;

int clearIthBit(int num, int i)
{
    return num & ~(1 << i); // left shift
}
