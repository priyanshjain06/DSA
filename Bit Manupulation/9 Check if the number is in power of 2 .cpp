#include <iostream>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0; //REVIEW returns a bool
}

