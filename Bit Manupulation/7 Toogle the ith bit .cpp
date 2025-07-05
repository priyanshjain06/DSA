#include <iostream>
using namespace std;

int toggleIthBit(int num, int i)
{
    return num ^ (1 << i); // REVIEW -  left shift
}

