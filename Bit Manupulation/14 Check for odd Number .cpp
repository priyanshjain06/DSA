#include <iostream>
using namespace std;

bool isOdd(int num)
{
    return (num & 1) != 0; // Check the least significant bit (LSB)
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isOdd(num))
        cout << num << " is Odd." << endl;
    else
        cout << num << " is Even." << endl;

    return 0;
}
