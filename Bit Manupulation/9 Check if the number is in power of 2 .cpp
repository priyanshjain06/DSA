#include <iostream>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0; //REVIEW returns a bool
}
int main()
{
    int num = 16; // Example number
    if (isPowerOfTwo(num))
    {
        cout << num << " is a power of 2." << endl;
    }
    else
    {
        cout << num << " is not a power of 2." << endl;
    }
    return 0;
}
