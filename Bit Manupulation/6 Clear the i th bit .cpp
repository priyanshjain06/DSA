#include <iostream>
using namespace std;

int clearIthBit(int num, int i)
{
    return num & ~(1 << i); // left shift
}
int main()
{
    int num = 5; // Binary: 0101
    int i = 2;

    int result = clearIthBit(num, i);
    cout << "Number after clearing the " << i << "-th bit: " << result << endl; // Output: 1, Binary: 0001

    return 0;
}
