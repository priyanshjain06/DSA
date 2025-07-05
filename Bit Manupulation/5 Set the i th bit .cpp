#include <iostream>
using namespace std;
int setIthBit(int num, int i)
{
    return num | (1 << i); // REVIEW -  left shift
}
