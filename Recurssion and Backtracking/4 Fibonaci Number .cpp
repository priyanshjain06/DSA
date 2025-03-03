#include <iostream>
using namespace std;
// Function to calculate and display the Fibonacci series :
void printFibonacciSeries(int n)
{
    if (n == 0)
    {
        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << 0; //NOTE 0 1 1 2 3 5
    }
    else
    {
        int secondLast = 0; // (i-2)th term
        int last = 1;       // (i-1)th term
        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << secondLast << " " << last << " ";
        int cur; // ith term 
        for (int i = 2; i <= n; i++) //REVIEW start from 2
        {
            cur = last + secondLast;
            secondLast = last;
            last = cur;
            cout << cur << " ";
        }
    }
    cout << endl;
}
