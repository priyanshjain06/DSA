#include <iostream>
using namespace std ;
int multiply(int A, int B)
{
    int result = 0;
    bool isNegative = (A < 0) ^ (B < 0); // Check if result should be negative
    A = abs(A);
    B = abs(B);
    
    while (B > 0)
    {
        if (B & 1)
        { // If B is odd, add A to the result
            result += A;
        }
        A <<= 1; // Double A
        B >>= 1; // Halve B

        // REVIEW - In C++, the <<= and >>= operators are compound assignment operators for bitwise shifts, just like += is for addition.
    }

    return isNegative ? -result : result; //REVIEW
}
int main()
{
    int A = -3, B = 5;
    cout << "Result of multiplication: " << multiply(A, B) << endl;
    return 0;
}
