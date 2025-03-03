#include <iostream>
using namespace std;

int func(int n)
{
    if (n == 0)
        return 0;

    return n + func(n - 1); // REVIEW Functional recurssion
}

// REVIEW -  or
// class Solution {
//   public:
//     long long sumOfSeries(long long n) {
//         // Formula for the sum of cubes of the first n natural numbers
//         long long sum = (n * (n + 1)) / 2;
//         return sum * sum; //REVIEW
//     }
// };  