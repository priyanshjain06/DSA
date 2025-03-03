#include <iostream>
using namespace std;

int divide(int A, int B)
{
    if (B == 0) //REVIEW 
    {
        throw invalid_argument("Division by zero is undefined");
    }

    bool isNegative = (A < 0) ^ (B < 0); // Check if result should be negative
    A = abs(A);
    B = abs(B);

    int quotient = 0;
    int temp = B;

    while (A >= B)
    {
        int multiple = 1;
        while ((temp << 1) <= A)
        {
            temp <<= 1;
            multiple <<= 1;
        }
        A -= temp; // to deal with -ve
        quotient += multiple;
        temp = B; // Reset temp to B for the next iteration
    }
    return isNegative ? -quotient : quotient;
}
int main()
{
    int A = 15, B = 3;
    cout << "Result of division: " << divide(A, B) << endl;
    return 0;
}
