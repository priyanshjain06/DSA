#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool areCoPrime(int a, int b)
{
    return gcd(a, b) == 1;
}
