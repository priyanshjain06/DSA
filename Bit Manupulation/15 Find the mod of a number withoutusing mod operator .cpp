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
int main()
{
    int A = 17;
    int B = 5;
    cout << "Modulus of " << A << " with " << B << " is: " << modWithoutMod(A, B) << endl;
    return 0;
}
