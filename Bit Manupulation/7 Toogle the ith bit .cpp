#include <iostream>
using namespace std;

int toggleIthBit(int num, int i)
{
    return num ^ (1 << i); // REVIEW -  left shift
}

int main()
{
    int num = 5; // Binary: 0101
    int i = 1;

    int result = toggleIthBit(num, i);
    cout << "Number after toggling the " << i << "-th bit: " << result << endl; // Output: 7, Binary: 0111

    return 0;
}
