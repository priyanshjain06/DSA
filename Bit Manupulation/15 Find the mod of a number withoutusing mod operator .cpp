#include <iostream>
using namespace std;

int modWithoutMod(int A, int B)
{
    while (A >= B)
    {
        A -= B;
    }
    return A;
}
