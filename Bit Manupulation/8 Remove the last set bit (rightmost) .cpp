#include <iostream>
using namespace std;

int removeRightmostSetBit(int x)
{
    return x & (x - 1);
}
int main()
{
    int x = 12; // Example number
    cout << "Before removing last set bit: " << x << endl;
    x = removeRightmostSetBit(x);
    cout << "After removing last set bit: " << x << endl;
    return 0;
}
