// time complexity O(n) and space comlexity O(1)
// NOTE here N is the size of the array (size of given array+1)

// you can also use xor rember xor of 2^2 is o while xor of 2^0 is 2 while xor of 2^2^2 is 2

#include <iostream>
#include <vector>
using namespace std;


int missingNumber(vector<int> &a, int N)
{

    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}


int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}