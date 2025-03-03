#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b; // Step 1: a becomes a ^ b
    b = a ^ b; // Step 2: b becomes a (original value of a)
    a = a ^ b; // Step 3: a becomes b (original value of b)
}
int main()
{
    int a = 5, b = 3;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    return 0;
}
